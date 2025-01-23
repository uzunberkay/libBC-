#include"bclib.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdint.h>





const uint64_t factor[] =
{
	 1,                    // 0!
	 1,                    // 1!
	 2,                    // 2!
	 6,                    // 3!
	 24,                   // 4!
	 120,                  // 5!
	 720,                  // 6!
	 5040,                 // 7!
	 40320,                // 8!
	 362880,               // 9!
	 3628800,              // 10!
	 39916800,             // 11!
	 479001600,            // 12!
	 6227020800,           // 13!
	 87178291200,          // 14!
	 1307674368000,        // 15!
	 20922789888000,       // 16!
	 355687428096000,      // 17!
	 6402373705728000,     // 18!
	 121645100408832000,   // 19!
	 2432902008176640000,  // 20!
};

const char* days[] =
{	"None",
	"Pazar" ,
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
};
const char* months[] = {
	"None",
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
};

void	bclib_random(void) { srand(time(NULL)); }
void	bclib_buble_sort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				bclib_generic_swap(array + j, array + j + 1, sizeof(int));
			}

		}

	}
}

int		bclib_qsort_int_cb(const void* arg1, const void* arg2)
{
	return *(const int*)arg1 - *(const int*)arg2;
	/*
	* Kullanýmý qsort(arr,SIZE,sizeof(int),qsort_cb);
	*/
}
int		bclib_qsort_double_cb(const void* arg1, const void* arg2)
{
	return *(const double*)arg1 > *(const double*)arg2 ? 1 : *(const double*)arg1 < *(const double*)arg2 ? -1 : 0;
	/*
	* Kullanýmý qsort(arr,SIZE,sizeof(int),qsort_cb);
	*/
}
int    bclib_qsort_float_cb(const void* arg1, const void* arg2)
{
	return *(const float*)arg1 > *(const float*)arg2 ? 1 : *(const float*)arg1 < *(const float*)arg2 ? -1 : 0;
}

int	  bclib_qsort_string_cb(const void* arg1, const void* arg2)
{
	const char* str1 = *(const char**)arg1;
	const char* str2 = *(const char**)arg2;
	return strcmp(str1, str2);
}


/*
 * @brief Genel bir sýralama fonksiyonu. Belirli bir veri tipindeki diziyi sýralar.
 *
 * @param array Sýralanacak dizinin baþlangýç adresi.
 * @param size Dizideki eleman sayýsý.
 * @param sz Her bir elemanýn boyutu (byte cinsinden).
 * @param fp Elemanlarý karþýlaþtýrmak için kullanýlan callback fonksiyonu.
 *
 * Callback Fonksiyonlarý:
 *   - Eðer diziniz `int` türündeyse: `bclib_qsort_int_cb` fonksiyonunu kullanýn.
 *   - Eðer diziniz `float` türündeyse: `bclib_qsort_float_cb` fonksiyonunu kullanýn.
 *   - Eðer diziniz `double` türündeyse: `bclib_qsort_double_cb` fonksiyonunu kullanýn.
 *
 * Callback fonksiyonunun imzasý:
 *   int comparator(const void* a, const void* b);
 *   - Eðer a < b ise negatif bir deðer döndürmelidir.
 *   - Eðer a == b ise 0 döndürmelidir.
 *   - Eðer a > b ise pozitif bir deðer döndürmelidir.
 *
 * Kullaným Örnekleri:
 *   1. int dizisini sýralama:
 *      int arr[] = {5, 3, 8, 6, 2};
 *      bclib_sort_array(arr, 5, sizeof(int), bclib_qsort_int_cb);
 *
 *   2. float dizisini sýralama:
 *      float f_arr[] = {3.14, 1.59, 2.71};
 *      bclib_sort_array(f_arr, 3, sizeof(float), bclib_qsort_float_cb);
 *
 *   3. double dizisini sýralama:
 *      double d_arr[] = {3.1415, 2.7182, 1.6180};
 *      bclib_sort_array(d_arr, 3, sizeof(double), bclib_qsort_double_cb);
 */
void bclib_sort_array(void* array, size_t size , size_t sz, fptr compare)
{
	/*
	* Buraya belki switch case ile yapabilirim ???
	*/
	qsort(array, size, sz, compare);

}
int*	bclib_binary_Search(const int* arr, size_t size, int key)
{
	int* first = (int*)arr;
	int* end = (int*)arr + size - 1;

	while (end >= first)
	{
		int* mid = first + (end - first) / 2;
		if (*mid == key)
		{
			return mid;
		}
		else if (key > *mid)
		{
			first = mid + 1;
		}
		else if (key < *mid)
		{
			end = mid - 1;
		}
	}

	return NULL;
}


int*	bclib_find_value(const int* arr, size_t size, int key)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (*(arr + i) == key)
			return (int*)(arr + i);

	}
	return NULL;	
}

void	bclib_print_array(const int* arr, size_t size)
{
	printf("\n");
	for (size_t i = 0; i < size; i++)
	{
		if (i && i % 5 == 0)
			printf("\n");

		printf("%02d ", *(arr + i));

	}
}


void	bclib_puts(const char* str)
{
	if (!str) { return NULL; }
	while (*str)
		putchar(*str++);

	putchar('\n');
}


void*    bclib_generic_swap(void* arg1, void* arg2, size_t size)
{
	char* vp1 = (char*)arg1;
	char* vp2 = (char*)arg2;

	while (size--)
	{
		char temp = *vp1;
		*vp1++ = *vp2;
		*vp2++ = temp;
	}
	return arg1;
}

void* bclib_reverse(void* arg, size_t size, size_t sz)
{
	char* vpfirst = (char*)arg;
	char* vpend   = (char*)arg + (sz * (size - 1));

	while (vpfirst < vpend )
	{
		bclib_generic_swap(vpfirst, vpend, sz);
		vpfirst += sz, vpend -= sz;
		
	}

	return arg;
}

void* bclib_memset(void* arg, int value, size_t size)
{
	char* vptr = (char*)arg;
	while (size--)
	{
		*vptr++ = (char)value;
	}

	return arg;
}
void* bclib_memcpy(void* arg1, const void* arg2, size_t size)
{
	char* vpfirst = (char*)arg1;
	const char* vpend = (char*)arg2;

	while (size--)
	{
		*vpfirst++ = *vpend++;
	}

	return arg1;
}
void* bclib_memchr(const void* arg, int value, size_t size)
{
	const char* vp = arg;
	while (size--)
	{
		if (*vp == (char)value)
		{
			return (char*)vp;
		}
		*vp++;
	}
	return NULL;
}
int bclib_memcmp(const void* arg1, const void* arg2, size_t size)
{
	const char* vp1 = (const char*)arg1;
	const char* vp2 = (const char*)arg2;
	int flag = 0;

	while (size--)
	{
		if (*vp1 != *vp2)
		{
			flag = 1;
			break;
		}
		++vp1, ++vp2;
	}
	if (!flag)
		return 0;

	return *vp1 > *vp2 ? 1 : -1;
}

void* bclib_generic_search(const void* arg, size_t size, size_t sz,void* key)
{
	if (!arg) { return NULL; }
	const char* vp = (const char*)arg;

	while (size--)
	{
		if(!memcmp(vp,key,sz))
			return (char*)vp;
		vp += sz;
	
	}
	return NULL;
}

int* bclib_get_min(const int* arr, size_t size)
{
	const int* min = arr;
	for (size_t i = 1; i < size; ++i)
	{
		if (*(arr + i) < *min)
		{
			min = (arr + i);
		}
	}

	return (int*)min;
}

int* bclib_get_max(const int* arr, size_t size)
{
	const int* max = arr;

	for (size_t i = 0; i < size; ++i)
	{
		if (*(arr + i) > *max)
		{
			max = (arr + i);
		}

	}

	return (int*)max;
}

size_t bclib_strlen(const char* arg)
{
	
	const char* argTemp = arg;
	while (*argTemp) ++argTemp;

	return argTemp - arg;

}
char* bclib_strcpy(char* pdest, const char* psource)
{
	if (!pdest || !psource) { return NULL; }
	char* pstart = pdest;
	while (*pdest++ = *psource++);

	return pstart;

}

char* bclib_strcat(char* pdest, const char* psource)
{
	if (!pdest || !psource) { return NULL; }

	char* vp = pdest + bclib_strlen(pdest);

	while (*vp++ = *psource++);

	return pdest;
}
int bclib_strcmp(const char* arg1, const char* arg2)
{

	while (*arg1 && (*arg1 == *arg2))
	{
		++arg1, ++arg2;
	}
	return *(unsigned char*)arg1 - *(unsigned char*)arg2;
}

char* bclib_strrchr(const char* arg, char ch)
{
	const char* last = NULL;
	while (*arg)
	{
		if (*arg == ch)
			last = arg;
		++arg;
	}
	return (char*)last;
}

void bclib_string_print(const char** str, size_t size)
{
	while (size--)
		puts(*str++);
}

int is_empty(const int* arr, size_t size)
{
	while (size--)
		if (*arr++)
			return 0;

	return 1;
}

int sumIntArray(const int* array, size_t size)
{
	int result = 0; 
	while (size--) result += *array++;
	return result;
}
