#ifndef __DEFINES_TYPES_INT32_64_H
#define __DEFINES_TYPES_INT32_64_H

/*
	With out this header i will cry after every build
*/

#ifdef __WIN64__
	typedef long long ZLONG, *PZLONG, *ZLONG_PTR;
	typedef unsigned long long ZWORD, *PZWORD, *ZWORD_PTR;

	#define INT32_64_0 0ui64
	#define INT32_64_MAX 0xFFFFFFFFFFFFFFFFui64
	#define INT32_64_SIZE 8
#else
	typedef long ZLONG, *PZLONG, *ZLONG_PTR;
	typedef unsigned long ZWORD, *PZWORD, *ZWORD_PTR;

	#define INT32_64_0 0UL
	#define INT32_64_MAX 0xFFFFFFFFUL
	#define INT32_64_SIZE 4
#endif

#endif