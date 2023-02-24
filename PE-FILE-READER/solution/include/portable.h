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
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned long long QWORD;
typedef unsigned long LONG;
typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;

#define ___IMAGE_NT_OPTIONAL_HDR32_MAGIC       0x10b
#define ___IMAGE_NT_OPTIONAL_HDR64_MAGIC       0x20b
#define ___IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16
#define ___IMAGE_DOS_SIGNATURE                 0x5A4D

#define ___IMAGE_DIRECTORY_ENTRY_EXPORT          0
#define ___IMAGE_DIRECTORY_ENTRY_IMPORT          1
#define ___IMAGE_DIRECTORY_ENTRY_RESOURCE        2
#define ___IMAGE_DIRECTORY_ENTRY_EXCEPTION       3
#define ___IMAGE_DIRECTORY_ENTRY_SECURITY        4
#define ___IMAGE_DIRECTORY_ENTRY_BASERELOC       5
#define ___IMAGE_DIRECTORY_ENTRY_DEBUG           6
#define ___IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7
#define ___IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8
#define ___IMAGE_DIRECTORY_ENTRY_TLS             9
#define ___IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10
#define ___IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11
#define ___IMAGE_DIRECTORY_ENTRY_IAT            12
#define ___IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13
#define ___IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14

#define IMAGE_SIZEOF_SHORT_NAME              8
#define IMAGE_SIZEOF_SECTION_HEADER          40


/**
 * @brief Dos header
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_DOS_HEADER {
    //! e_magic
    WORD e_magic;
    //!e_cblp
    WORD e_cblp;
    //!e_cp
    WORD e_cp;
    //!e_crlc
    WORD e_crlc;
    //!e_cparhdr
    WORD e_cparhdr;
    //!e_minalloc
    WORD e_minalloc;
    //!e_maxalloc
    WORD e_maxalloc;
    //! e_ss
    WORD e_ss;
    //! e_sp
    WORD e_sp;
    //! e_csum
    WORD e_csum;
    //! e_ip
    WORD e_ip;
    //! e_cs
    WORD e_cs;
    //! e_lfarlc
    WORD e_lfarlc;
    //! e_ovno
    WORD e_ovno;
    //! e_res[4]
    WORD e_res[4];
    //! e_oemid
    WORD e_oemid;
    //! e_oeminfo
    WORD e_oeminfo;
    //! e_res2[10]
    WORD e_res2[10];
    //! e_lfanew
    LONG e_lfanew;
} IMAGE_DOS_HEADER;
#if defined _MSC_VER
#pragma pack(pop)
#endif


/**
 * @brief Data directory
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_DATA_DIRECTORY {
    //! Virtual Address
    DWORD VirtualAddress;
    //! Size
    DWORD Size;
} IMAGE_DATA_DIRECTORY;
#if defined _MSC_VER
#pragma pack(pop)
#endif


/**
 * @brief Optional header
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_OPTIONAL_HEADER {
    //! Magic
    WORD Magic;
    //! MajorLinkerVersion
    BYTE MajorLinkerVersion;
    //! MinorLinkerVersion
    BYTE MinorLinkerVersion;
    //! Size Of Code
    DWORD SizeOfCode;
    //! SizeOfInitializedData
    DWORD SizeOfInitializedData;
    //! SizeOfUninitializedData
    DWORD SizeOfUninitializedData;
    //! Address Of EntryPoint
    DWORD AddressOfEntryPoint;
    //! Base Of Code
    DWORD BaseOfCode;
    //! Base Of Data
    DWORD BaseOfData;
    //! Image Base
    DWORD ImageBase;
    //! SectionAlignment
    DWORD SectionAlignment;
    //! FileAlignment
    DWORD FileAlignment;
    //! MajorOperatingSystemVersion
    WORD MajorOperatingSystemVersion;
    //! MinorOperatingSystemVersion
    WORD MinorOperatingSystemVersion;
    //! MajorImageVersion
    WORD MajorImageVersion;
    //! MinorImageVersion
    WORD MinorImageVersion;
    //! MajorSubsystemVersion
    WORD MajorSubsystemVersion;
    //! MinorSubsystemVersion
    WORD MinorSubsystemVersion;
    //! Win32VersionValue
    DWORD Win32VersionValue;
    //! SizeOfImage
    DWORD SizeOfImage;
    //! SizeOfHeaders
    DWORD SizeOfHeaders;
    //! CheckSum
    DWORD CheckSum;
    //! Subsystem
    WORD Subsystem;
    //! DllCharacteristics
    WORD DllCharacteristics;
    //! Size Of Stack Reserve
    DWORD SizeOfStackReserve;
    //! Size Of Stack Commit
    DWORD SizeOfStackCommit;
    //! Size Of Heap Reserve
    DWORD SizeOfHeapReserve;
    //! Size Of Heap Commit
    DWORD SizeOfHeapCommit;
    //! Loader Flags
    DWORD LoaderFlags;
    //! Number Of Rva And Sizes
    DWORD NumberOfRvaAndSizes;
    //! Data Directory
    IMAGE_DATA_DIRECTORY DataDirectory[___IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER32;
#if defined _MSC_VER
#pragma pack(pop)
#endif


/**
 * @brief Optional header(64)
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_OPTIONAL_HEADER64 {
    //! Magic
    WORD Magic;
    //! MajorLinkerVersion
    BYTE MajorLinkerVersion;
    //! MinorLinkerVersion
    BYTE MinorLinkerVersion;
    //! Size Of Code
    DWORD SizeOfCode;
    //! SizeOfInitializedData
    DWORD SizeOfInitializedData;
    //! SizeOfUninitializedData
    DWORD SizeOfUninitializedData;
    //! Address Of EntryPoint
    DWORD AddressOfEntryPoint;
    //! Base Of Code
    DWORD BaseOfCode;
    //! Image Base
    ULONGLONG ImageBase;
    //! SectionAlignment
    DWORD SectionAlignment;
    //! FileAlignment
    DWORD FileAlignment;
    //! MajorOperatingSystemVersion
    WORD MajorOperatingSystemVersion;
    //! MinorOperatingSystemVersion
    WORD MinorOperatingSystemVersion;
    //! MajorImageVersion
    WORD MajorImageVersion;
    //! MinorImageVersion
    WORD MinorImageVersion;
    //! MajorSubsystemVersion
    WORD MajorSubsystemVersion;
    //! MinorSubsystemVersion
    WORD MinorSubsystemVersion;
    //! Win32VersionValue
    DWORD Win32VersionValue;
    //! SizeOfImage
    DWORD SizeOfImage;
    //! SizeOfHeaders
    DWORD SizeOfHeaders;
    //! CheckSum
    DWORD CheckSum;
    //! Subsystem
    WORD Subsystem;
    //! DllCharacteristics
    WORD DllCharacteristics;
    //! Size Of Stack Reserve
    ULONGLONG SizeOfStackReserve;
    //! Size Of Stack Commit
    ULONGLONG SizeOfStackCommit;
    //! Size Of Heap Reserve
    ULONGLONG SizeOfHeapReserve;
    //! Size Of Heap Commit
    ULONGLONG SizeOfHeapCommit;
    //! Loader Flags
    DWORD LoaderFlags;
    //! Number Of Rva And Sizes
    DWORD NumberOfRvaAndSizes;
    //! Data Directory
    IMAGE_DATA_DIRECTORY DataDirectory[___IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER64;
#if defined _MSC_VER
#pragma pack(pop)
#endif

/**
 * @brief File header
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_FILE_HEADER {
    //! Machine
    WORD Machine;
    //! Number Of Sections
    WORD NumberOfSections;
    //! TimeDateStamp
    DWORD TimeDateStamp;
    //! Pointer To SymbolTable
    DWORD PointerToSymbolTable;
    //! Number Of Symbols
    DWORD NumberOfSymbols;
    //! Size Of OptionalHeader
    WORD SizeOfOptionalHeader;
    //! Characteristics
    WORD Characteristics;
} IMAGE_FILE_HEADER;
#if defined _MSC_VER
#pragma pack(pop)
#endif

/**
 * @brief Nt headers
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_NT_HEADERS64 {
    //! Signature
    DWORD Signature;
    //! FileHeader
    IMAGE_FILE_HEADER FileHeader;
    //! OptionalHeader
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS;
#if defined _MSC_VER
#pragma pack(pop)
#endif


/**
 * @brief Section header
 */
#if defined _MSC_VER
#pragma pack(push,1)
#endif
typedef struct
#if defined __GNUC__
        __attribute__((packed))
#endif
IMAGE_SECTION_HEADER {
    //! Name
    BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
    //! Misc
    union {
        //! Physical Address of MISC
        DWORD PhysicalAddress;
        //! Virtual Size of MISC
        DWORD VirtualSize;
    } Misc;
    //! Virtual Address
    DWORD VirtualAddress;
    //! Size Of RawData
    DWORD SizeOfRawData;
    //! Pointer To RawData
    DWORD PointerToRawData;
    //! Pointer To Relocations
    DWORD PointerToRelocations;
    //! Pointer To Linenumbers
    DWORD PointerToLinenumbers;
    //! Number Of Relocations
    WORD NumberOfRelocations;
    //! Number Of Linenumbers
    WORD NumberOfLinenumbers;
    //! Characteristics
    DWORD Characteristics;
} IMAGE_SECTION_HEADER;
#if defined _MSC_VER
#pragma pack(pop)
#endif
