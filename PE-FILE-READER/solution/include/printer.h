//
// Created by Asus on 24.02.2023.
//

#ifndef SECTION_EXTRACTOR_PRINTER_H
#define SECTION_EXTRACTOR_PRINTER_H

void usage(void);
void print_answer(IMAGE_FILE_HEADER header_sections, char *section_name,FILE *pe_file,FILE *output);
#endif //SECTION_EXTRACTOR_PRINTER_H
