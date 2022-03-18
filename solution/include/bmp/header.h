#ifndef BMP_HEADER_H
#define BMP_HEADER_H

#define HDR_BF_TYPE 0x4D42
#define HDR_OFF_BITS 54
#define HDR_BI_SIZE 40
#define HDR_BI_PLANES 1
#define HDR_BI_BIT_COUNT 24
#define HDR_BI_PPM 2834
#define HDR_CLR_USED 0
#define HDR_CLR_IMP 0
#define HDR_BF_RESERVED 0
#define HDR_BI_COMPRESSION 0

#include <stdio.h>
#include "../image/image.h"

struct __attribute__(( packed )) bmp_header {
	uint16_t bfType;
	uint32_t bfileSize;
	uint32_t bfReserved;
	uint32_t bOffBits;
	uint32_t biSize;
	uint32_t biWidth;
	uint32_t biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
	uint32_t biCompression;
	uint32_t biSizeImage;
	uint32_t biXPelsPerMeter;
	uint32_t biYPelsPerMeter;
	uint32_t biClrUsed;
	uint32_t biClrImportant;
};

struct bmp_header create_empty_header();
struct bmp_header create_header( const struct image* img );

bool read_header ( FILE* in, struct bmp_header* h);
bool write_header ( FILE* in, struct bmp_header h );

size_t get_bi_width ( const struct bmp_header h );
size_t get_bi_height ( const struct bmp_header h );
size_t get_off_bits ( const struct bmp_header h );

#endif //BMP_HEADER_H


