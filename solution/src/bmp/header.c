#include <stdint.h>
#include <stdbool.h>

#include "../include/image/image.h"
#include "../include/bmp/padding.h"
#include "../include/bmp/header.h"

static bool header_signature_valid( const struct bmp_header h ) {
	return ( h.bfType == HDR_BF_TYPE );
}

static uint32_t bfile_size ( const struct image* img ) {
	return ( sizeof ( struct bmp_header ) + image_size_bytes( img ) + padding_image( img ) );
}

struct bmp_header create_empty_header() {
	return ( struct bmp_header ) { 0 };
}

struct bmp_header create_header( const struct image* img ) {
	
	return ( struct bmp_header ) {
		.bfType = HDR_BF_TYPE,
		.bfileSize = bfile_size( img ),
		.bfReserved = HDR_BF_RESERVED,
		.bOffBits = HDR_OFF_BITS,
		.biSize = HDR_BI_SIZE,
		.biWidth = img -> width,
		.biHeight = img -> height,
		.biPlanes = HDR_BI_PLANES,
		.biBitCount = HDR_BI_BIT_COUNT,
		.biCompression = HDR_BI_COMPRESSION,
		.biSizeImage = ( bfile_size( img ) - HDR_OFF_BITS ),
		.biXPelsPerMeter = HDR_BI_PPM,
		.biYPelsPerMeter = HDR_BI_PPM,
		.biClrUsed = HDR_CLR_USED,
		.biClrImportant = HDR_CLR_IMP
	};
}

bool read_header ( FILE* in, struct bmp_header* h) {

	if ( !fread( h, sizeof( struct bmp_header ), 1, in ) )
		return false;

	if ( !header_signature_valid( *h ) )
		return false;

	if ( h -> biHeight <= 0 || h -> biWidth <= 0 )
		return false;

	return true;
}

bool write_header ( FILE* out, struct bmp_header h ) {
	if ( !fwrite( &h, sizeof ( struct bmp_header ), 1, out ) )
		return false;
	return true;
}

size_t get_bi_width ( const struct bmp_header h ) {
	return h.biWidth;
}

size_t get_bi_height ( const struct bmp_header h ) {
	return h.biHeight;
}

size_t get_off_bits ( const struct bmp_header h ) {
	return h.bOffBits;
}

