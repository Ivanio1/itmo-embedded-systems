//
// Created by Asus on 24.02.2023.
//

/**
 * @file
 * @brief File fo reading PE files
 */
#include "pe_reader.h"

//! Dos header
IMAGE_DOS_HEADER header_dos = {0};
//! PE header
IMAGE_NT_HEADERS header_pe = {0};

/**
 * @brief Reading data from PE file
 * @param argv Array with file information
 */
void read_data(char *argv[]){
    /// Input PE file
    FILE *pe_file = fopen(argv[1], "rb");
    /// Output bin file
    FILE *output = fopen(argv[3], "wb");

    fread(&header_dos, sizeof header_dos, 1, pe_file);
    fseek(pe_file, header_dos.e_lfanew, 0);
    fread(&header_pe, sizeof header_pe, 1, pe_file);

    /// File header
    IMAGE_FILE_HEADER header_sections = header_pe.FileHeader;

    /// Section name
    char *section_name =  argv[2];

    print_answer(header_sections,section_name,pe_file,output);

}
