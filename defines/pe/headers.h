#ifndef __DEFINES_PE_HEADERS_H
#define __DEFINES_PE_HEADERS_H

/*
	We dont't need NT Header 
*/

typedef struct __pe_image_dos_header_t
{
	SKIP_INT16(1, 30);
	LONG e_lfanew;
}IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct __pe_image_file_header_t
{
	WORD wMachine;
	WORD wNumberOfSections;
	DWORD dwTimeDateStamp;
	DWORD dwPointerToSymbolTable;
	DWORD dwNumberOfSymbols;
	WORD wSizeOfOptionalHeader;
	WORD wCharact;
}IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

#define IMAGE_FILE_HEADER_SIZE 20

typedef struct __pe_image_data_directory_t
{
	DWORD dwVirtualAddress; //base + this; Its RVA i don't know why its named VirtualAddress
	DWORD dwSize;
}IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct __pe_image_optional_header64_t
{
	WORD wMagic;
	SKIP_INT8(link_ver, 2); //MajorLinkerVersion, MinorLinkerVersion
	DWORD dwSizeOfCode;
	DWORD dwSizeOfInitedData;
	DWORD dwSizeOfUninitedData;
	DWORD dwAddressOfEntryPoint;
	DWORD dwBaseOfCode;

	#ifdef __WIN32__
		DWORD dwBaseOfData;
	#endif

	ZWORD zwImageBase;
	SKIP_INT32(alignment, 2); //SectionAlignment, FileAlignment
	SKIP_INT16(more_ver, 8); //MajorOperatingSystemVersion, MinorOperatingSystemVersion, MajorImageVersion, MinorImageVersion, MajorSubsystemVersion, MinorSubsystemVersion, Win32VersionValue
	DWORD dwSizeOfImage;
	DWORD dwSizeOfHeaders;
	DWORD dwCheckSum;
	WORD wSubSystem;
	WORD wDllCharact;
	ZWORD zwSizeOfStackReserve;
	ZWORD zwSizeOfStackCommit;
	ZWORD zwSizeOfHeapReserve;
	ZWORD zwSizeOfHeapCommit;
	DWORD dwLoaderFlags;
	DWORD dwNumberOfRvaAndSizes;
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
}IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;

typedef struct __pe_image_section_header_t
{
	BYTE sName[8];

	union {
		DWORD dwPhysicalAddress;
		DWORD dwVirtualSize;
	}Misc;

	DWORD dwVirtualAddress;
	DWORD dwSizeOfRawData;
	DWORD dwPointerToRawData;
	DWORD dwPointerToRelocations;
	DWORD dwPointerToLineNumbers;
	WORD wNumberOfRelocations;
	WORD wNumberOfLineNumbers;
	DWORD dwCharact;
}IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define PeGetFileHeaderFromBase(BASEADDR) (PIMAGE_FILE_HEADER)(((CHAR_PTR)BASEADDR) +  ((PIMAGE_DOS_HEADER)BASEADDR)->e_lfanew + INT32_SIZE);
#define PeGetOptionalHeaderFromBase(BASEADDR) (PIMAGE_OPTIONAL_HEADER)(((CHAR_PTR)BASEADDR) + ((PIMAGE_DOS_HEADER)BASEADDR)->e_lfanew + INT32_SIZE + IMAGE_FILE_HEADER_SIZE);
#define PeGetOptionalHeaderFromFileHeader(FHEAD_BASEADDR) (PIMAGE_OPTIONAL_HEADER)((CHAR_PTR)FHEAD_BASEADDR + IMAGE_FILE_HEADER_SIZE);

#define PeGetDirectoryFromOpt(OPT_BASEADDR, DATADIR_ID) (PIMAGE_DATA_DIRECTORY)(&OPT_BASEADDR->DataDirectory[DATADIR_ID]);
#define PeGetFirstSectionFromFileHeader(FHEAD_BASEADDR) (PIMAGE_SECTION_HEADER)((CHAR_PTR)FHEAD_BASEADDR + ((FHEAD_BASEADDR)->wSizeOfOptionalHeader) + IMAGE_FILE_HEADER_SIZE)

#endif
