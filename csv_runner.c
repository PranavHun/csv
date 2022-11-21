#include "csv.h"

int main(int argc, char **argv)
{
    char *first_10_chars;
    if (argc > 1)
    {
        ERRCODE e = csv_read(&first_10_chars, argv[1], '\n', ',');
        switch (e)
        {
        case OKAY:
            printf("Read the following\n");
            printf("%s\n", first_10_chars);
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
    free(first_10_chars);
    return EXIT_SUCCESS;
}