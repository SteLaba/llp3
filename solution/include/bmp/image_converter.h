#ifndef BMP_IMAGE_CONVERTER_H
#define BMP_IMAGE_CONVERTER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../image/image.h"
#include "header.h"

enum read_status {
	READ_OK = 0,
	READ_FROM_NULL_FILE,
	READ_INVALID_HEADER,
	READ_INVALID_BITS,
};

enum write_status {
	WRITE_OK = 0,
	WRITE_ERROR
}; 

bool to_image_convert ( FILE* in, const struct bmp_header h, struct image* img );

bool from_image_convert ( FILE* out, const struct image* img );

enum read_status from_bmp( FILE* in, struct image* img );

enum write_status to_bmp( FILE* out, struct image* img );	

#endif //BMP_IMAGE_CONVERTER_H
