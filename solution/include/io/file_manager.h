#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdbool.h>
#include <stdio.h>

bool open_file (FILE** file, const char* path, const char* mode);

bool close_file (FILE* file);

#endif //FILE_MANAGER_H
