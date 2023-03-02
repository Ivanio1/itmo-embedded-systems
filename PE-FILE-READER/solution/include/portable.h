#ifndef __studio_h_

#include <stdio.h>

#endif

#ifndef __stdlib_h_

#include <stdlib.h>

#endif

#ifndef __stdint_h_

#include <stdint.h>

#endif

#ifndef __string_h_

#include <string.h>

#endif

/**
 * Structure of PE header with specific fields
 */

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif
struct
#if defined __clang__ || defined __GNUC__
        __attribute__((packed))
#endif
PEHeader {
    ///The number that identifies the type of target machine
    int16_t Machine;
    ///The number of sections. This indicates the size of the section table, which immediately follows the headers.
    int16_t NumberOfSections;
    ///The low 32 bits of the number of seconds since 00:00 January 1, 1970 (a C run-time time_t value), which indicates when the file was created.
    int32_t TimeDateStamp;
    ///The file offset of the COFF symbol table, or zero if no COFF symbol table is present.
    int32_t PointerToSymbolTable;
    ///The number of entries in the symbol table.
    int32_t NumberOfSymbols;
    ///The size of the optional header, which is required for executable files but not for object files
    int16_t SizeOfOptionalHeader;
    ///The flags that indicate the attributes of the file
    int16_t Characteristics;

};
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
 * Structure of section header with specific fields
 */
#ifdef _MSC_VER
#pragma pack(push, 1)
#endif
struct
#if defined __clang__ || defined __GNUC__
        __attribute__((packed))
#endif
SectionHeader {
    ///An 8-byte, null-padded UTF-8 encoded string.
    uint8_t name[8];
    ///Misc
    union {
        ///Physical Size
        uint32_t PhysicalSize;
        ///The total size of the section when loaded into memory.
        uint32_t VirtualSize;
    } Misc;
    ///For executable images, the address of the first byte of the section relative to the image base when the section is loaded into memory.
    uint32_t VirtualAddress;
    ///The size of the section or the size of the initialized data on disk.
    uint32_t SizeOfRawData;
    ///The file pointer to the first page of the section within the COFF file.
    uint32_t PointerToRawData;
    ///The file pointer to the beginning of relocation entries for the section.
    uint32_t PointerToRelocations;
    ///The file pointer to the beginning of line-number entries for the section.
    uint16_t PointerToLinenumbers;
    ///The number of relocation entries for the section.
    uint32_t NumberOfRelocations;
    ///The number of line-number entries for the section.
    uint16_t NumberOfLinenumbers;
    ///The number of line-number entries for the section.
    uint32_t Characteristics;

};

#ifdef _MSC_VER
#pragma pack(pop)
#endif


/**
 * Structure of PE file with specific fields
 */
#ifdef _MSC_VER
#pragma pack(push, 1)
#endif
struct
#if defined __clang__ || defined __GNUC__
        __attribute__((packed))
#endif
PEFile {
    ///Identifies the file as a PE format image file
    uint32_t signature;
    ///Header of PE file
    struct PEHeader header;
    ///Headers of sections
    struct SectionHeader *sectionHeaders;

};
#ifdef _MSC_VER
#pragma pack(pop)
#endif
