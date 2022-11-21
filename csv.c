#include "csv.h"

ERRCODE csv_read(CSVFILE *data, const char *filename, const char separator_line, const char separator_column)
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
    fseek(csv_file, 0, SEEK_END);
    int filesize = ftell(csv_file);
    fseek(csv_file, 0, SEEK_SET);

    data->file_string = (char *)malloc((filesize + 1) * sizeof(char));
    memset(data->file_string, '\0', filesize + 1);
    // fread_s(data->file_string, sizeof(char) * filesize, sizeof(char), filesize, csv_file);
    char ch;
    data->number_of_rows = 0;
    data->number_of_columns = 1;
    for (int i = 0; i < filesize; ++i)
    {
        ch = fgetc(csv_file);

        if (ch == separator_line)
        {
            data->number_of_rows++;
            ch = '|';
        }
        else if (ch == separator_column)
            data->number_of_columns++;
        data->file_string[i] = ch;
    }

    // END: TODO

    fclose(csv_file);
    return OKAY;
}

void csv_free(CSVFILE *data)
{
    free(data->file_string);
}