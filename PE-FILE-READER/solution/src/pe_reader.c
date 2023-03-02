//
// Created by Asus on 24.02.2023.
//

/**
 * @file
 * @brief File fo reading PE files
 */
#include "pe_reader.h"


/**
 * @brief Reading data from PE file
 * @param in Input file
 * @param file Structure of PE file
 */
void read_data(FILE *in, struct PEFile *file) {
    //DOS offset
    fseek(in, 0x3c, SEEK_SET);
    //Signature offset
    uint32_t offset;
    fread(&offset, sizeof(uint32_t), 1, in);
    fseek(in, (long)offset, SEEK_SET);
    fread(&file->signature, sizeof(file->signature), 1, in);
    fread(&file->header, sizeof(file->header), 1, in);
    file->sectionHeaders = malloc(file->header.NumberOfSections * sizeof(struct SectionHeader));
    fseek(in, file->header.SizeOfOptionalHeader, SEEK_CUR);
    fread(file->sectionHeaders, sizeof(struct SectionHeader), file->header.NumberOfSections, in);
}
