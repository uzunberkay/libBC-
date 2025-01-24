#ifndef BCLIB_H
#define BCLIB_H

#include <stdint.h> // uint32_t, size_t gibi türler için gerekli
#include <stddef.h> // size_t gibi standart türler için gerekli

extern const uint64_t factor[];
extern const char* days[];
extern const char* months[];

#define FACTOR_SIZE			21
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
#define MOD(x,m)			((x) % (m))
#define ZERO_ARRAY(arr)		(memset((arr),0,sizeof((arr))))
#define FILL_ARRAY(arr,val)	(memset((arr),(int)(val),sizeof(arr)))

#define START_TIMER()		clock_t start = clock()
#define END_TIMER()			printf("Elapsed Time: %.5f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC)


#ifdef LOG
#define LOG_ERROR(msg)  fprintf(stderr, "[ERROR] %s:%d: %s\n", __FILE__, __LINE__, (msg))
#endif





typedef int (*fptr)(const void*, const void*); 


void		bclib_bubble_sort(int* array, int size);                        
void		bclib_sort_array(void* array, size_t size, size_t sz, fptr compare); 
int*		bclib_binary_search(const int* arr, size_t size, int key);      
int*		bclib_find_value(const int* arr, size_t size, int key);         
int*		bclib_get_min(const int* array, size_t size);                   
int*		bclib_get_max(const int* arr, size_t size);                     
void		bclib_print_array(const int* arr, size_t size);                 


void*		bclib_memset(void* arg, int value, size_t size);                
void*		bclib_memcpy(void* arg1, const void* arg2, size_t size);        
void*		bclib_memchr(const void* arg, int value, size_t size);          
void*		bclib_generic_swap(void* arg1, void* arg2, size_t size);        
void*		bclib_reverse(void* arg, size_t size, size_t sz);               

size_t		bclib_strlen(const char* str);                                  
char*		bclib_strcpy(char* pdest, const char* psource);                 
char*		bclib_strcat(char* pdest, const char* psource);                
int			bclib_strcmp(const char* arg1, const char* arg2);               
char*		bclib_strrchr(const char* arg, char ch);                       

void		bclib_random(void);                                            


int			bclib_qsort_int_cb(const void* arg1, const void* arg2);         
int			bclib_qsort_double_cb(const void* arg1, const void* arg2);      
int			bclib_qsort_float_cb(const void* arg1, const void* arg2);       
int			bclib_qsort_string_cb(const void* arg1, const void* arg2);


void		bclib_string_print(const char** str, size_t size);
int			is_empty(const int* arr, size_t size);
int			sumIntArray(const int* array, size_t size);




#endif // BCLIB_H
