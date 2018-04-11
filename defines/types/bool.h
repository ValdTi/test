#ifndef __DEFINES_TYPES_BOOL_H
#define __DEFINES_TYPES_BOOL_H

#define TRUE 1
#define FALSE 0
#define ERROR -1

/*
	Why is BOOL defined as int ? Is ment to store 2 values, 1 and 0. Don't look at ERROR -1
*/
typedef int WIN_BOOL, *PWIN_BOOL, *WIN_BOOL_PTR;
typedef char BOOL, *PBOOL, *BOOL_PTR;

#endif
