// Copyright (C) 2025 therealblue24 under the MIT license.
// base utils
#ifndef BASE_H_
#define BASE_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define zz_str2(x) x

/* stringifies `x` */
#define xstr(x) zz_str2(#x)

/* converts `x` to `void*` */
#define type_erase(x) ((void *)(x))

/* calloc(1, size) with error checking */
void *zalloc(size_t size);

/* calloc(count, size) with error checking */
void *zcalloc(size_t count, size_t size);

/* realloc(ptr, newsize) with error checking */
void *zrealloc(void *ptr, size_t newsize);

/* duplicates memory `mem` with size `size` */
void *memdup(void *mem, size_t size);

/* Errors out program with a reason (can be used like printf) */
#define ERROR(reas, ...)                                                    \
	do {                                                                    \
		fprintf(stderr, "ERROR: %s:%d: %s: " reas "\n", __FILE__, __LINE__, \
				__func__ __VA_OPT__(, ) __VA_ARGS__);                       \
		exit(EXIT_FAILURE);                                                 \
	} while(0);

/* Like error, but warns and doesn't exit out */
#define WARN(reas, ...)                                                    \
	do {                                                                   \
		fprintf(stderr, "WARN: %s:%d: %s: " reas "\n", __FILE__, __LINE__, \
				__func__ __VA_OPT__(, ) __VA_ARGS__);                      \
	} while(0);

/* assertion macros */
#ifdef NDEBUG

#define ASSERT(cond, reas, ...) \
	do {                        \
	} while(0);
#else

// Assertion failed: (cond), function __func__, file __FILE__, line __LINE__.
// Reason: reas
#define ASSERT(cond, reas, ...)                                               \
	if(!(cond)) {                                                             \
		fprintf(stderr,                                                       \
				"Assertion failed: " xstr(                                    \
					(cond)) ", function %s, file %s, line %d.\nReason: " reas \
							"\n",                                             \
				__func__, __FILE__, __LINE__ __VA_OPT__(, ) __VA_ARGS__);     \
		exit(EXIT_FAILURE);                                                   \
	}

#endif

/* like ASSERT but is never impacted by NDEBUG */
#define ENSURE(cond, reas, ...)                                               \
	if(!(cond)) {                                                             \
		fprintf(stderr,                                                       \
				"Assertion failed: " xstr(                                    \
					(cond)) ", function %s, file %s, line %d.\nReason: " reas \
							"\n",                                             \
				__func__, __FILE__, __LINE__ __VA_OPT__(, ) __VA_ARGS__);     \
		exit(EXIT_FAILURE);                                                   \
	}

#endif /* BASE_H_ */
