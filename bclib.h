#ifndef BCLIB_H
#define BCLIB_H

#include <stdint.h> // uint32_t, size_t gibi t�rler i�in gerekli
#include <stddef.h> // size_t gibi standart t�rler i�in gerekli

extern const uint64_t factor[];
extern const char* days[];
extern const char* months[];

#define FACTOR_SIZE		21
// ----- Makrolar -----
#define SQUARE(x)			((x) * (x))            
#define IS_ODD(x)			(((x) & 1) ? 1 : 0)    
#define IS_EVEN(x)			(!IS_ODD((x)))         
#define POWER_OF_TWO(x)		((x) && !((x) & ((x) -1)) )
#define asize(x)			(sizeof(x) / sizeof(x[0]))
#define FAKTORIYEL(x)		((x) < 0 || ( (x) >= FACTOR_SIZE ) ? -1 : factor[(x)]
#define DAY(x)				(x) <= 0 || x > 7 ? days[0] : days[(x)]
#define ABS(x)				(x) > 0 ? (x) : -(x) 
#define MONTH(x)			(x) <= 0 || x > 12 ? months[0] : months[(x)]
#define MAX(a,b)			(a) > (b) ? (a) : (b)
#define MIN(a,b)			(a) < (b) ? (a) : (b)

#define SET_BIT(x, n)		((x) |= (1U << (n)))    
#define CLEAR_BIT(x, n)		((x) &= ~(1U << (n)))   
#define TOGGLE_BIT(x, n)	((x) ^= (1U << (n)))   
#define CHECK_BIT(x, n)		(!!((x) & (1U << (n)))) 



// ----- T�r Tan�mlar� -----
typedef int (*fptr)(const void*, const void*); 

// ----- Dizi ��lemleri -----
void    bclib_bubble_sort(int* array, int size);                        // Bubble sort algoritmas�
void    bclib_sort_array(void* array, size_t size, size_t sz, fptr compare); // Genel bir diziyi s�ralar (qsort benzeri)
int* bclib_binary_search(const int* arr, size_t size, int key);      // Binary search algoritmas�
int* bclib_find_value(const int* arr, size_t size, int key);         // Dizide bir de�eri arar
int* bclib_get_min(const int* array, size_t size);                   // Dizideki minimum de�eri bulur
int* bclib_get_max(const int* arr, size_t size);                     // Dizideki maksimum de�eri bulur
void    bclib_print_array(const int* arr, size_t size);                 // Bir diziyi ekrana yazd�r�r

// ----- Bellek ��lemleri -----
void* bclib_memset(void* arg, int value, size_t size);                // Bellek alan�n� belirli bir de�erle doldurur
void* bclib_memcpy(void* arg1, const void* arg2, size_t size);        // Bellek kopyalama
void* bclib_memchr(const void* arg, int value, size_t size);          // Bellekte bir de�eri arar
void* bclib_generic_swap(void* arg1, void* arg2, size_t size);        // �ki bellek alan�n� swap yapar
void* bclib_reverse(void* arg, size_t size, size_t sz);               // Belle�i ters �evirir

// ----- String ��lemleri -----
size_t  bclib_strlen(const char* str);                                  // String uzunlu�unu hesaplar
char* bclib_strcpy(char* pdest, const char* psource);                 // String kopyalar
char* bclib_strcat(char* pdest, const char* psource);                 // �ki stringi birle�tirir
int     bclib_strcmp(const char* arg1, const char* arg2);               // �ki stringi kar��la�t�r�r
char* bclib_strrchr(const char* arg, char ch);                        // Stringde bir karakterin son ge�ti�i yeri bulur

// ----- Rastgele Say� �retimi -----
void    bclib_random(void);                                             // Rastgele say� �retimi

// ----- Kar��la�t�rma Callback Fonksiyonlar� -----
int     bclib_qsort_int_cb(const void* arg1, const void* arg2);         // `qsort` i�in integer kar��la�t�rma callback'i
int     bclib_qsort_double_cb(const void* arg1, const void* arg2);      // `qsort` i�in double kar��la�t�rma callback'i
int     bclib_qsort_float_cb(const void* arg1, const void* arg2);       // `qsort` i�in float kar��la�t�rma callback'i
int	  bclib_qsort_string_cb(const void* arg1, const void* arg2);


void bclib_string_print(const char** str, size_t size);
int is_empty(const int* arr, size_t size);
int sumIntArray(const int* array, size_t size);




#endif // BCLIB_H
