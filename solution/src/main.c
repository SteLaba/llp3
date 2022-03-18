#include <stdio.h>
#include <sysexits.h>

#include "../include/io/file_manager.h"
#include "../include/io/print_err.h"
#include "../include/image/image.h"
#include "../include/bmp/image_converter.h"
#include "../include/xforms/rotate.h"


enum error_codes read_error_codes[] = {
	[ READ_FROM_NULL_FILE ]	= ERROR_READ_NULL_FILE,
 	[ READ_INVALID_HEADER ] = ERROR_INVALID_HEADER,
	[ READ_INVALID_BITS   ] = ERROR_INVALID_BITS,
};

int main( int argc, char** argv ) {
	enum read_status read_status;
	enum write_status write_status;	

	if ( argc < 3 ) {
		print_err( ERROR_ARGS );
		return 1;
	}

	FILE* in = NULL;

	if ( !open_file( &in, argv[1], "rb" ) ) {
		print_err( ERROR_OPEN );
        	return 1;	
	}

	struct image pre_rot_img = {0};
	read_status = from_bmp(in, &pre_rot_img);
	
	if ( read_status ) {
		print_err( read_error_codes[ read_status ] );
		close_file( in );
		return 1;
	}

	if( !close_file(in) ) {
        	print_err( ERROR_CLOSE );
        	destroy_image( &pre_rot_img );
        	return 1;
    	}

	struct image rot_img = rotate( &pre_rot_img );
    	destroy_image( &pre_rot_img );

	FILE* out = NULL;

    	if( !open_file( &out, argv[2], "wb" ) ) {
		print_err( ERROR_OPEN );
		destroy_image( &rot_img );
		return 1;
    	}

	write_status = to_bmp( out, &rot_img );

	if ( write_status ) {
		print_err( ERROR_WRITE );
		destroy_image( &rot_img );
		close_file( out );
		return 1;
    	}

    	destroy_image( &rot_img );

    	if ( !close_file( out ) ) {
        	print_err( ERROR_CLOSE );
        	return 1;
    	}
    	return 0;
}
