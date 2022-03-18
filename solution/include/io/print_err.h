#ifndef ERROR_PRINTER_H
#define ERROR_PRINTER_H

enum error_codes {
	ERROR_READ_NULL_FILE,
	ERROR_INVALID_HEADER,
	ERROR_INVALID_BITS,

	ERROR_WRITE,
	ERROR_CLOSE,
	ERROR_OPEN,

	ERROR_ARGS	
};

void print_err( enum error_codes code );

#endif //ERROR_PRINTER_H
