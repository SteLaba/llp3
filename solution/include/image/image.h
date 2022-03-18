#ifndef IMAGE_H
#define IMAGE_H

#include <inttypes.h>
#include <stdbool.h>

#include "pixel.h"

struct image {
    uint32_t width, height;
    struct pixel* data;
};

struct image create_image (uint32_t width, uint32_t height);

uint32_t image_size_bytes ( const struct image* img);

void destroy_image (struct image* img);

bool set_px_coords (struct image* img, struct pixel pixel, uint32_t x, uint32_t y);

struct pixel get_px_coords (const struct image* img, uint32_t x, uint32_t y);

#endif //IMAGE_H
