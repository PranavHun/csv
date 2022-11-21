#include "csv.h"

int main(int argc, char **argv)
{
    CSVFILE csv_text;
    if (argc > 1)
    {
        ERRCODE e = csv_read(&csv_text, argv[1], '\n', ',');
        switch (e)
        {
        case OKAY:
            printf("Read the following\n");
            char print_text[75];
            strncpy_s(print_text, sizeof(char) * 75, csv_text.file_string, 74);
            print_text[74] = '\0';
            printf("%s ...\n", print_text);
            printf("(%zd, %zd)\n", csv_text.number_of_rows, csv_text.number_of_columns);
            break;
        case FILE_NOT_FOUND:
            printf("File %s was not found.\n", argv[1]);
            break;
        default:
            printf("Error reading csv file.");
            break;
        }
    }
    else
    {
        printf("Please provide csv file path.\nUsage:\ncsv_runner PATH\n");
        return EXIT_FAILURE;
    }
    csv_free(&csv_text);
    return EXIT_SUCCESS;
}
