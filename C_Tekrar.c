#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"bclib.h"
#include<string.h>
#include<time.h>
#define SIZE	20


void test_sort_int_array(int* arr, size_t size) {
    printf("Before sorting int array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bclib_sort_array(arr, size, sizeof(int), bclib_qsort_int_cb);

    printf("After sorting int array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
void test_sort_float_array(float* arr, size_t size) {
    printf("Before sorting float array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    bclib_sort_array(arr, size, sizeof(float), bclib_qsort_float_cb);

    printf("After sorting float array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
}
void test_sort_double_array(double* arr, size_t size) {
    printf("Before sorting double array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n\n");

    bclib_sort_array(arr, size, sizeof(double), bclib_qsort_double_cb);

    printf("After sorting double array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");
}
void test_sort_string_array(const char* arr[], size_t size) {
    printf("Before sorting string array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    bclib_sort_array((void*)arr, size, sizeof(char*), bclib_qsort_string_cb);

    printf("After sorting string array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}




uint64_t faktoriyel(int ival)
{
    if (ival == 1 || ival == 0)
        return 1;

    uint64_t result = 1;
    for (size_t i = 1; i <= ival; ++i)
    {
        result *= i;

    }

    return result;
}


int main()
{
    bclib_random();
    int arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }
    test_sort_int_array(arr, SIZE);
    printf("\n");
    float float_arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        
        float_arr[i] = rand() * 0.3  + 0.3;
    }
    test_sort_float_array(float_arr, SIZE);
    printf("\n");

    double double_arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        double_arr[i] = rand() * 0.23;

    }
    test_sort_double_array(double_arr, SIZE);
    printf("\n");

    printf("\nTesting string array sorting:\n");

    const char* string_arr[] = { "banana", "apple", "cherry", "blueberry" };
    bclib_string_print(string_arr, 4);
    test_sort_string_array(string_arr, sizeof(string_arr) / sizeof(string_arr[0]));

    //printf("%d" NULL - NULL -1 );

    bclib_string_print(string_arr, 4);

}


