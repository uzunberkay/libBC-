#ifndef BCLIB_H
#define BCLIB_H

#include <stdint.h> // uint32_t, size_t gibi türler için gerekli
#include <stddef.h> // size_t gibi standart türler için gerekli

extern const int factor[];

// ----- Makrolar -----
#define SQUARE(x)       ((x) * (x))            // Bir sayýnýn karesini hesaplar
#define IS_ODD(x)       (((x) & 1) ? 1 : 0)    // Sayýnýn tek olup olmadýðýný kontrol eder
#define IS_EVEN(x)      (!IS_ODD((x)))         // Sayýnýn çift olup olmadýðýný kontrol eder
#define POWER_OF_TWO(x) ((x) && !((x) & ((x) -1)) )
#define asize(x)	(sizeof(x) / sizeof(x[0]))
#define FAKTORIYEL(x)	factor[x]

// ----- Tür Tanýmlarý -----
typedef int (*fptr)(const void*, const void*); // Genel karþýlaþtýrma fonksiyonu iþaretçisi

// ----- Dizi Ýþlemleri -----
void    bclib_bubble_sort(int* array, int size);                        // Bubble sort algoritmasý
void    bclib_sort_array(void* array, size_t size, size_t sz, fptr compare); // Genel bir diziyi sýralar (qsort benzeri)
int* bclib_binary_search(const int* arr, size_t size, int key);      // Binary search algoritmasý
int* bclib_find_value(const int* arr, size_t size, int key);         // Dizide bir deðeri arar
int* bclib_get_min(const int* array, size_t size);                   // Dizideki minimum deðeri bulur
int* bclib_get_max(const int* arr, size_t size);                     // Dizideki maksimum deðeri bulur
void    bclib_print_array(const int* arr, size_t size);                 // Bir diziyi ekrana yazdýrýr

// ----- Bellek Ýþlemleri -----
void* bclib_memset(void* arg, int value, size_t size);                // Bellek alanýný belirli bir deðerle doldurur
void* bclib_memcpy(void* arg1, const void* arg2, size_t size);        // Bellek kopyalama
void* bclib_memchr(const void* arg, int value, size_t size);          // Bellekte bir deðeri arar
void* bclib_generic_swap(void* arg1, void* arg2, size_t size);        // Ýki bellek alanýný swap yapar
void* bclib_reverse(void* arg, size_t size, size_t sz);               // Belleði ters çevirir

// ----- String Ýþlemleri -----
size_t  bclib_strlen(const char* str);                                  // String uzunluðunu hesaplar
char* bclib_strcpy(char* pdest, const char* psource);                 // String kopyalar
char* bclib_strcat(char* pdest, const char* psource);                 // Ýki stringi birleþtirir
int     bclib_strcmp(const char* arg1, const char* arg2);               // Ýki stringi karþýlaþtýrýr
char* bclib_strrchr(const char* arg, char ch);                        // Stringde bir karakterin son geçtiði yeri bulur

// ----- Rastgele Sayý Üretimi -----
void    bclib_random(void);                                             // Rastgele sayý üretimi

// ----- Karþýlaþtýrma Callback Fonksiyonlarý -----
int     bclib_qsort_int_cb(const void* arg1, const void* arg2);         // `qsort` için integer karþýlaþtýrma callback'i
int     bclib_qsort_double_cb(const void* arg1, const void* arg2);      // `qsort` için double karþýlaþtýrma callback'i
int     bclib_qsort_float_cb(const void* arg1, const void* arg2);       // `qsort` için float karþýlaþtýrma callback'i
int	  bclib_qsort_string_cb(const void* arg1, const void* arg2);

uint64_t bclib_get_faktoriyel(int ival);
void bclib_string_print(const char** str, size_t size);

#endif // BCLIB_H
