//
// Created by Asus on 24.02.2023.
//

/**
 * @file
 * @brief File for printing information
 */
#include "portable.h"

/**
 * @brief Print the usage
 */
void usage(void) {
    printf("Usage: ./section-extracter <source-pe-file> <section-name> <output-bin-image>");
}

/**
 * @brief Print information about section
 * @param in Input file
 * @param out Output file
 * @param peFile Structure of PE file
 * @param name Name of section
 */
void print_answer(FILE *in, FILE *out, struct PEFile *peFile, char *name) {
    for (int16_t i = 0; i < peFile->header.NumberOfSections; i++) {
        if (strcmp((char*)peFile->sectionHeaders[i].name, name) == 0) {
            struct SectionHeader section_header = peFile->sectionHeaders[i];
            printf("%X ", section_header.Misc.VirtualSize);
            printf("%X ", section_header.VirtualAddress);
            printf("%X ", section_header.PointerToRawData);
            printf("%X ", section_header.SizeOfRawData);
            printf("%X ", section_header.PointerToRelocations);
            printf("%X ", section_header.NumberOfRelocations);
            printf("%X ", section_header.PointerToLinenumbers);
            printf("%X ", section_header.NumberOfLinenumbers);
            printf("%X", section_header.Characteristics);
            fseek(in, (long) section_header.PointerToRawData, SEEK_SET);
            char *section = malloc(section_header.SizeOfRawData);
            fread(section, section_header.SizeOfRawData, 1, in);
            fwrite(section, section_header.SizeOfRawData, 1, out);
            free(section);
        }
    }
}
