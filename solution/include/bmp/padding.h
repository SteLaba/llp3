#ifndef BMP_PADDING_H
#define BMP_PADDING_H

#include <stdio.h>
#include <stdint.h>

#include "../image/image.h"

size_t padding_row ( uint32_t width );

size_t padding_image ( const struct image* img );

bool write_padding ( FILE* out, uint32_t width );

#endif //BMP_PADDING_H
