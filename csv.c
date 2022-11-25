#include "csv.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

ERRCODE csv_read(CSVFILE *data, const char *filename, const char separator_line,
                 const char separator_column)
{
  FILE *csv_file = fopen(filename, "r");
  if (!csv_file)
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

  char ch;
  data->number_of_rows = 0;
  data->number_of_cells = 0;
  data->number_of_columns = 0;
  size_t column_count_check = 1;

  const size_t BUFFER_INCREMENT = 100;
  size_t cell_start_size = BUFFER_INCREMENT;
  size_t cell_start_counter = 0;
  data->cell_start = (size_t *)malloc(sizeof(size_t) * cell_start_size);
  data->cell_start[cell_start_counter] = 0;

  for (size_t i = 0; i < filesize; ++i)
  {
    ch = fgetc(csv_file);

    if (ch == separator_column || ch == separator_line)
    {
      if (ch == separator_line)
      {
        data->number_of_rows++;
        if (data->number_of_columns == 0)
          data->number_of_columns = column_count_check;
        else if (data->number_of_columns != column_count_check)
          printf("Error while parsing CSV file! %zd, %zd\n", data->number_of_columns, column_count_check);
        column_count_check = 0;
      }
      ++column_count_check;
      data->number_of_cells++;
      if (cell_start_counter >= cell_start_size)
      {
        cell_start_size += BUFFER_INCREMENT;
        data->cell_start = (size_t *)realloc(data->cell_start,
                                             sizeof(size_t) * cell_start_size);
      }
      cell_start_counter++;
      data->cell_start[cell_start_counter] = i + 1;
    }
    data->file_string[i] = ch;
  }
  data->cell_start = (size_t *)realloc(
      data->cell_start, sizeof(size_t) * (cell_start_counter + 1));
  data->cell_start[cell_start_counter] = filesize;

  // END: TODO

  fclose(csv_file);
  return OKAY;
}

char *csv_read_cell_to_str(CSVFILE *data, size_t row, size_t col)
{
  if (row < data->number_of_rows && col < data->number_of_columns)
  {
    size_t cell_number = row * data->number_of_columns + col;
    size_t len =
        data->cell_start[cell_number + 1] - 1 - data->cell_start[cell_number];
    char *value = malloc(sizeof(char) * (len + 1));
    strncpy(value, data->file_string + data->cell_start[cell_number], len);
    value[len] = '\0';
    return value;
  }
  else
  {
    return NULL;
  }
}

void csv_free(CSVFILE *data)
{
  free(data->cell_start);
  free(data->file_string);
}