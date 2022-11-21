#include "csv.h"

ERRCODE csv_read(char **data, const char *filename, char separator_line, char separator_column)
{
    FILE *csv_file;
    errno_t e = fopen_s(&csv_file, filename, "r");
    if (e != 0)
        return FILE_NOT_FOUND;

    /* TODO: This is just Temporary Logic
     * Final logic will have the csv file validated,
     * then returned in the form of struct with vital data,
     * to process it further into arrays.
     */
    *data = (char *)malloc(11 * sizeof(char));
    memset(*data, '\0', 11 * sizeof(char));
    for (int i = 0; i < 10; ++i)
    {
        if (!feof(csv_file))
            *((*data) + i) = fgetc(csv_file);
    }
    // END: TODO

    fclose(csv_file);
    return OKAY;
}