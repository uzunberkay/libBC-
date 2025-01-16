#include"bclib.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>

void bclib_random(void) { srand(time(NULL)); }

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
	* Kullan�m� qsort(arr,SIZE,sizeof(int),qsort_cb);
	*/
}
int		bclib_qsort_double_cb(const void* arg1, const void* arg2)
{
	return *(const double*)arg1 > *(const double*)arg2 ? 1 : *(const double*)arg1 < *(const double*)arg2 ? -1 : 0;
	/*
	* Kullan�m� qsort(arr,SIZE,sizeof(int),qsort_cb);
	*/
}
int    bclib_qsort_float_cb(const void* arg1, const void* arg2)
{
	return *(const float*)arg1 > *(const float*)arg2 ? 1 : *(const float*)arg1 < *(const float*)arg2 ? -1 : 0;
}


/*
 * @brief Genel bir s�ralama fonksiyonu. Belirli bir veri tipindeki diziyi s�ralar.
 *
 * @param array S�ralanacak dizinin ba�lang�� adresi.
 * @param size Dizideki eleman say�s�.
 * @param sz Her bir eleman�n boyutu (byte cinsinden).
 * @param fp Elemanlar� kar��la�t�rmak i�in kullan�lan callback fonksiyonu.
 *
 * Callback Fonksiyonlar�:
 *   - E�er diziniz `int` t�r�ndeyse: `bclib_qsort_int_cb` fonksiyonunu kullan�n.
 *   - E�er diziniz `float` t�r�ndeyse: `bclib_qsort_float_cb` fonksiyonunu kullan�n.
 *   - E�er diziniz `double` t�r�ndeyse: `bclib_qsort_double_cb` fonksiyonunu kullan�n.
 *
 * Callback fonksiyonunun imzas�:
 *   int comparator(const void* a, const void* b);
 *   - E�er a < b ise negatif bir de�er d�nd�rmelidir.
 *   - E�er a == b ise 0 d�nd�rmelidir.
 *   - E�er a > b ise pozitif bir de�er d�nd�rmelidir.
 *
 * Kullan�m �rnekleri:
 *   1. int dizisini s�ralama:
 *      int arr[] = {5, 3, 8, 6, 2};
 *      bclib_sort_array(arr, 5, sizeof(int), bclib_qsort_int_cb);
 *
 *   2. float dizisini s�ralama:
 *      float f_arr[] = {3.14, 1.59, 2.71};
 *      bclib_sort_array(f_arr, 3, sizeof(float), bclib_qsort_float_cb);
 *
 *   3. double dizisini s�ralama:
 *      double d_arr[] = {3.1415, 2.7182, 1.6180};
 *      bclib_sort_array(d_arr, 3, sizeof(double), bclib_qsort_double_cb);
 */
void bclib_sort_array(void* array, size_t size , size_t sz, fptr fp)
{
	qsort(array, size, sz, fp);

}
int*	bclib_binary_Search(const int* arr, size_t size, int key)
{
	int* first = arr;
	int* end = arr + size - 1;

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
	while (*str)
		putchar(*str++);

	putchar('\n');
}


char* bclib_strcpy(char* pdest, const char* psource)
{
	char* ptest = pdest;
	while (*pdest++ = psource++);

	return ptest;
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
	const char* vpend   = (char*)arg2;

	while (size--)
	{
		*vpfirst++ = *vpend++;
	}

	return arg1;
}
void* bclib_memchr(const void* arg, int value, size_t size)
{
	const char* vp = (char*)arg;
	while (size--)
	{
		if (*vp == (char)value)
		{
			return vp;
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
	int* min = arr;
	for (size_t i = 1; i < size; ++i)
	{
		if (*(arr + i) < *min)
		{
			min = (arr + i);
		}
	}

	return min;
}

int* bclib_get_max(const int* arr, size_t size)
{
	int* max = arr;

	for (size_t i = 0; i < size; ++i)
	{
		if (*(arr + i) > *max)
		{
			max = (arr + i);
		}

	}

	return max;
}

void a(void)
{
	printf("\n");
}