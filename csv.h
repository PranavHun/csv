#ifndef _CSV_BY_PRANAVHUN_H
#define _CSV_BY_PRANAVHUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    OKAY,
    FILE_NOT_FOUND,
    LINE_SEPARATOR_NOT_FOUND,
    COLUMN_SEPARATOR_NOT_FOUND
} ERRCODE;

typedef struct
{
    char *file_string;
    size_t number_of_rows;
    size_t number_of_columns;
} CSVFILE;

ERRCODE csv_read(CSVFILE *data, const char *filename, char separator_line, char separator_column);
void csv_free(CSVFILE *data);

#endif