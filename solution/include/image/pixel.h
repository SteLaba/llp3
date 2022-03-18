#ifndef PIXEL_H
#define PIXEL_H

#include <inttypes.h>

struct __attribute__((packed)) pixel {
    uint8_t b, g, r;
};

#endif //PIXEL_H
