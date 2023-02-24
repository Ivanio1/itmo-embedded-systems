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
    if (argc < 3) {
        usage();
        return -1;
    }
    read_data(argv);
    return 0;
}
