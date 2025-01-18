#include "bclib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ---------- Rastgele Sayý Üretimi ----------
void bclib_random(void) {
    srand((unsigned int)time(NULL));
}

// ---------- Dizi Ýþlemleri ----------
void bclib_bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                bclib_generic_swap(array + j, array + j + 1, sizeof(int));
            }
        }
    }
}

int* bclib_binary_search(const int* arr, size_t size, int key) {
    const int* first = arr;
    const int* end = arr + size - 1;

    while (end >= first) {
        const int* mid = first + (end - first) / 2;
        if (*mid == key) {
            return (int*)mid;
        }
        else if (key > *mid) {
            first = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return NULL;
}

int* bclib_find_value(const int* arr, size_t size, int key) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return (int*)&arr[i];
        }
    }
    return NULL;
}

void bclib_print_array(const int* arr, size_t size) {
    printf("\n");
    for (size_t i = 0; i < size; i++) {
        if (i && i % 5 == 0) printf("\n");
        printf("%02d ", arr[i]);
    }
    printf("\n");
}

int* bclib_get_min(const int* arr, size_t size) {
    if (!arr || size == 0) return NULL;

    const int* min = arr;
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] < *min) min = &arr[i];
    }
    return (int*)min;
}

int* bclib_get_max(const int* arr, size_t size) {
    if (!arr || size == 0) return NULL;

    const int* max = arr;
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] > *max) max = &arr[i];
    }
    return (int*)max;
}

// ---------- Bellek Ýþlemleri ----------
void* bclib_generic_swap(void* arg1, void* arg2, size_t size) {
    unsigned char* a = (unsigned char*)arg1;
    unsigned char* b = (unsigned char*)arg2;

    while (size--) {
        unsigned char temp = *a;
        *a++ = *b;
        *b++ = temp;
    }
    return arg1;
}

void* bclib_memset(void* arg, int value, size_t size) {
    unsigned char* ptr = (unsigned char*)arg;
    while (size--) {
        *ptr++ = (unsigned char)value;
    }
    return arg;
}

void* bclib_memcpy(void* dest, const void* src, size_t size) {
    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (const unsigned char*)src;

    while (size--) {
        *d++ = *s++;
    }
    return dest;
}

void* bclib_memchr(const void* arg, int value, size_t size) {
    const unsigned char* ptr = (const unsigned char*)arg;

    while (size--) {
        if (*ptr == (unsigned char)value) {
            return (void*)ptr;
        }
        ptr++;
    }
    return NULL;
}

// ---------- String Ýþlemleri ----------
size_t bclib_strlen(const char* str) {
    const char* ptr = str;
    while (*ptr) ++ptr;
    return (size_t)(ptr - str);
}

char* bclib_strcpy(char* dest, const char* src) {
    if (!dest || !src) return NULL;

    char* start = dest;
    while ((*dest++ = *src++));
    return start;
}

char* bclib_strcat(char* dest, const char* src) {
    if (!dest || !src) return NULL;

    char* start = dest + bclib_strlen(dest);
    while ((*start++ = *src++));
    return dest;
}

int bclib_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

char* bclib_strrchr(const char* str, char ch) {
    const char* last = NULL;

    while (*str) {
        if (*str == ch) last = str;
        ++str;
    }
    return (char*)last;
}
