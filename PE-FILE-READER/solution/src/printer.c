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
 * @param header_sections Header of sections
 * @param section_name Name of section
 * @param pe_file Input file
 * @param output Output file
 */
void print_answer(IMAGE_FILE_HEADER header_sections, char *section_name,FILE *pe_file,FILE *output) {
    /// Pointer to sections
    IMAGE_SECTION_HEADER *sections = malloc(IMAGE_SIZEOF_SECTION_HEADER * header_sections.NumberOfSections);
    for (int i = 0; i < header_sections.NumberOfSections; i++) {
        IMAGE_SECTION_HEADER current_section = sections[i];
        fread(&(current_section), sizeof(IMAGE_SECTION_HEADER), 1, pe_file);
        if (strcmp((char *) current_section.Name, section_name) == 0) {
            printf("%lX ", current_section.Misc.VirtualSize);
            printf("%lX ", current_section.VirtualAddress);
            printf("%lX ", current_section.PointerToRawData);
            printf("%lX ", current_section.SizeOfRawData);
            printf("%lX ", current_section.PointerToRelocations);
            printf("%X ", current_section.NumberOfRelocations);
            printf("%lX ", current_section.PointerToLinenumbers);
            printf("%X ", current_section.NumberOfLinenumbers);
            printf("%lX", current_section.Characteristics);
            size_t pointer = current_section.PointerToRawData;
            fseek(pe_file, pointer, 0);
            char *section_with_code = malloc(current_section.SizeOfRawData);
            fread(section_with_code, current_section.SizeOfRawData, 1, pe_file);
            fwrite(section_with_code, current_section.SizeOfRawData, 1, output);
            free(section_with_code);
        }
    }
}
