#include <inttypes.h>
#include <stdbool.h>
#include <malloc.h>

#include "../include/image/image.h"

struct image create_image( uint32_t width, uint32_t height ) {
	struct image img = {0};
	img.width = width;
	img.height = height;
	img.data = malloc( height * width * sizeof( struct pixel ) );
	return img;
}

uint32_t image_size_bytes ( const struct image* img) {
	return ( img -> height * img -> width * sizeof( struct pixel ) );
}

void destroy_image( struct image* img ) {
	free( img -> data );
}

static bool check_x( const struct image* img, uint32_t x ) {
	return ( x <= img -> width);
}

static bool check_y( const struct image* img, uint32_t y ) {
	return ( y <= img -> height);
}

static bool check_coords( const struct image* img, uint32_t x, uint32_t y ) {
	return ( check_x( img, x ) && check_y( img, y ));
}

struct pixel get_px_coords( const struct image* img, uint32_t x, uint32_t y ) {
	return ( img -> data[ ( y * img -> width) + x ] ); 
}

bool set_px_coords( struct image* img, struct pixel const px, uint32_t x, uint32_t y ) {
	if( check_coords( img, x, y ) ) {
		( img -> data[ ( y * img -> width) + x ] ) = px;
		return true;
	}
	return false;
}
