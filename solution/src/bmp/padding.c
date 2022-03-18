#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../include/bmp/padding.h"
#include "../include/image/image.h"

size_t padding_row ( uint32_t width ) {
	return ( 4 - ( width * sizeof( struct pixel ) % 4 ) % 4 );
}

size_t padding_image ( const struct image* img ) {
	return ( img -> height * padding_row( img -> width ) );
}

bool write_padding ( FILE* out, uint32_t width ) {
	uint8_t padding_buffer[3] = {0};;
	
	if ( fwrite( padding_buffer, sizeof ( uint8_t ) * padding_row( width ), 1, out ))
		return true;

	return false;
}
