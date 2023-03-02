/**
 * @file
 * @brief Main application file
 */
#include "pe_reader.h"

/**
 * @brief Main function
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage();
        return 1;
    }
    ///Main PE file structure
    struct PEFile *peFile = malloc(sizeof(struct PEFile));
    ///Input file
    FILE *in = fopen(argv[1], "rb");
    ///Name of section
    char *name = argv[2];
    ///Output file
    FILE *out = fopen(argv[3], "wb");

    read_data(in, peFile);
    print_answer(in, out,peFile, name);

    free(peFile->sectionHeaders);
    free(peFile);
    fclose(in);
    fclose(out);
    return 0;
}
