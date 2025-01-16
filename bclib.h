#ifndef BCLÝB_H
#define BCLÝB_H


#include<stdint.h>

#define SQUARE(x)		((x) * (x))

typedef int(*fptr)(const void*, const void*);


void	bclib_buble_sort(int* array, int size);
int		bclib_qsort_int_cb(const void* arg1, const void* arg2);
int*	bclib_binary_Search(const int* arr, size_t size, int key);
int*	bclib_find_value(const int* arr, size_t size, int key);
void	bclib_print_array(const int* arr, size_t size);
void	bclib_puts(const char* str);
size_t	bclib_strlen(const char* str);
char*	bclib_strcpy(char* pdest, const char* psource);
void*	bclib_generic_swap(void* arg1, void* arg2, size_t size);
void*	bclib_reverse(void* arg, size_t size, size_t sz);
void*	bclib_memset(void* arg, int value, size_t size);
void*	bclib_memcpy(void* arg1, const void* arg2, size_t size);
void*	bclib_memchr(const void* arg, int value, size_t size);
int*	bclib_get_min(const int* array, size_t size);
int*	bclib_get_max(const int* arr, size_t size);
void	bclib_random(void);
void	bclib_sort_array(void* array, size_t size, size_t sz, fptr fp);
int	bclib_qsort_double_cb(const void* arg1, const void* arg2);
int    bclib_qsort_float_cb(const void* arg1, const void* arg2);
#endif