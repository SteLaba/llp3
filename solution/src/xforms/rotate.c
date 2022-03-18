#include <stdint.h>

#include "../include/xforms/rotate.h"

struct image rotate( struct image const* pre_rot_img ) {
    struct image rot_img = create_image(pre_rot_img -> height, pre_rot_img -> width);
    for (uint32_t i = 0; i < pre_rot_img -> height; i++) {
        for (uint32_t j = 0; j < pre_rot_img -> width; j++) {
            set_px_coords(&rot_img, get_px_coords(pre_rot_img, j, pre_rot_img -> height - i - 1),
                                     i, j);
        }
    }
    return rot_img;
}
