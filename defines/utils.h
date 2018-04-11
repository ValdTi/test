#ifndef __DEFINES_UTILS_H
#define __DEFINES_UTILS_H

#define _IN_ 
#define _OUT_ 
#define _IO_ 
#define _NON_      //not used but its needed (confusing)
#define _THREAD_   //ez
#define _NOT_SAFE_ //something that may the program
#define _BREAKS_   //something that will break the program on purpose

#define ON 1
#define OFF 0

typedef void VOID, *PVOID, **PVOID_PTR;
typedef void *HANDLE, **PHANDLE, **HANDLE_PTR;
typedef void *HMODULE, **PHMODULE, **HMODULE_PTR;

#define NULL ((PVOID)0)
#define IS_NULL(BLOCK) ((BLOCK) == NULL)
#define NOT_NULL(BLOCK) ((BLOCK) != NULL)

#define HAND_ERR ((HANDLE)-1)
#define IS_HAND_ERR(BLOCK) ((BLOCK) == HAND_ERR)
#define NOT_HAND_ERR(BLOCK) ((BLOCK) != HAND_ERR)

#define MOD_ERR ((HMODULE)0)
#define IS_MOD_ERR(BLOCK) ((BLOCK) == MOD_ERR)
#define NOT_MOD_ERR(BLOCK) ((BLOCK) != MOD_ERR)

#define SKIP_INT8(VNAME, TIMES)     BYTE  __skip_##VNAME[TIMES]
#define SKIP_INT16(VNAME, TIMES)    WORD  __skip_##VNAME[TIMES]
#define SKIP_INT32(VNAME, TIMES)    DWORD __skip_##VNAME[TIMES]
#define SKIP_INT64(VNAME, TIMES)    QWORD __skip_##VNAME[TIMES]
#define SKIP_INT32_64(VNAME, TIMES) ZWORD __skip_##VNAME[TIMES]

#ifdef __WIN64__
	#define WINAPI __cdecl
	#define PWINAPI __cdecl*
#else
	#define WINAPI __stdcall
	#define PWINAPI __stdcall*
#endif

#define STDCALL __stdcall
#define PSTDCALL __stdcall*
#define CDECL __cdecl
#define PCDECL __cdecl*

#endif
