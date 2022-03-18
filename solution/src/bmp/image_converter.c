#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../include/bmp/image_converter.h"
#include "../include/bmp/padding.h"

bool to_image_convert ( FILE* in, struct bmp_header h, struct image* img ) {
	*img = create_image( get_bi_width( h ), get_bi_height( h ) );
	
	fseek( in, get_off_bits( h ), SEEK_SET );

	for ( uint32_t i = 0; i < img -> height; i++ ) {
		if ( !fread( ( img -> data + img -> width * i ), ( sizeof( struct pixel ) * img -> width ), 1, in ) ) {
			destroy_image(img);
            		return false;
		}
		if (fseek(in, padding_row( img->width ), SEEK_CUR))
			return false;
	}
	
	return true;
}

bool from_image_convert ( FILE* out, const struct image* img ) {
	for ( uint32_t i = 0; i < img -> height; i++ ) {
		if ( !fwrite( ( img -> data + img -> width * i ), ( sizeof( struct pixel ) * img -> width ), 1, out ) )
            		return false;
		if ( !write_padding( out, img -> width)) 
			return false;
	}
	return true;
}

enum read_status from_bmp( FILE* in, struct image* img ) {
	if ( !in )
		return READ_FROM_NULL_FILE;
	struct bmp_header h = create_empty_header();
	if ( !read_header( in, &h ) )
		return READ_INVALID_HEADER;
	if ( !to_image_convert( in, h, img ) )
		return READ_INVALID_BITS;
	return READ_OK;
}

enum write_status to_bmp( FILE* out, struct image* img ) {
	struct bmp_header h = create_header( img );
	if ( !write_header( out, h ) )
		return WRITE_ERROR;
	if ( !from_image_convert( out, img ) )
		return WRITE_ERROR;
	return WRITE_OK;
	
}
