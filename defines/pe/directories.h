#ifndef __DEFINES_PE_DIRECTORIES_H
#define __DEFINES_PE_DIRECTORIES_H

typedef struct __pe_image_base_relocation_t
{
	DWORD dwVirtualAddress;
	DWORD dwSizeOfBlock;
}IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

#define IMAGE_REL_BASED_HIGHLOW 3
#define IMAGE_DIRECTORY_ENTRY_BASERELOC 5

typedef struct __pe_image_export_directory_t
{
	DWORD dwCharact;
	DWORD dwTimeDateStamp;
	SKIP_INT16(ver, 2);
	DWORD dwName;
	DWORD dwBase;
	DWORD dwNumberOfFunctions;
	DWORD dwNumberOfNames;
	DWORD dwAddressOfFunctions;
	DWORD dwAddressOfNames;
	DWORD dwAddressOfNameOrdinals;
}IMAGE_EXPORT_DIRECTORY, *PIMAGE_EXPORT_DIRECTORY;

#define IMAGE_DIRECTORY_ENTRY_EXPORT 0

#endif
