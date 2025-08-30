// Copyright (C) 2025 therealblue24 under the MIT license.
#include "base.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/* calloc(1, size) with error checking */
void *zalloc(size_t size)
{
	void *mem = malloc(size);
	ASSERT(mem, "failed to allocate %zu bytes of memory", size);
	memset(mem, 0, size);
	return mem;
}

/* calloc(count, size) with error checking */
void *zcalloc(size_t count, size_t size)
{
	void *mem = calloc(count, size);
	ASSERT(mem, "failed to allocate %zux%zu bytes of memory", size, count);
	return mem;
}

/* realloc(ptr, newsize) with error checking */
void *zrealloc(void *ptr, size_t newsize)
{
	void *newptr = realloc(ptr, newsize);
	ASSERT(newptr, "failed to reallocate %zu bytes of memory", newsize);
	return newptr;
}

/* duplicates memory `mem` with size `size` */
void *memdup(void *mem, size_t size)
{
	void *newmem = zalloc(size);
	memcpy(newmem, mem, size);
	return newmem;
}
