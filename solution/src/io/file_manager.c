#include <stdio.h>
#include <stdbool.h>

#include "../include/io/file_manager.h"

bool open_file( FILE** file, const char* path, const char* mode ) {
	if( path ) {
		*file = fopen( path, mode );
		return true;
	}
	return false;
}

bool close_file( FILE* file ) {
	if( file ) {
		fclose( file );
		return true; 
	}
	return false;
}
