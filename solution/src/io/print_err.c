#include <stdio.h>
#include "../include/io/print_err.h"

static const char* error_messages[] = {

	[ERROR_READ_NULL_FILE] = "ERROR! No file to read from!",
	[ERROR_INVALID_HEADER] = "ERROR! Invalid BMP header!",
	[ERROR_INVALID_BITS] = "ERROR! Invalid or corrupted data in file!",

	[ERROR_WRITE] = "ERROR! occured while writing to file!",
	[ERROR_CLOSE] = "ERROR! occured while closing the file!",
	[ERROR_OPEN]  = "ERROR! occured while opening the file!",

	[ERROR_ARGS] = "ERROR! Insufficient number of arguments provided!"
};

void print_err( enum error_codes code ) {
	fprintf(stderr, "%s \n", error_messages[code]);
}
