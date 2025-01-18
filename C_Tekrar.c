#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"bclib.h"
#include<string.h>
#include<time.h>
#define SIZE	20


// dosya isminin uzantisi  yoksa ise uzantısını .txt yapınız.
        // dosyanın uzantisi jpeg ise uzantisini png yapiniz.
        // dosya uzantısı .xls ise dosya uzantısı kaldırılacak.
        // bunların biri geçerli değilse dosya uzantısını .dat yap


void generic_func_test(void)
{
    float x = 3, y = 4;
    int a = 78, b = 39;
    double dval1 = 22.389, dval2 = 56.78;

    printf("X : %f  y : %f \n", x, y);
    bclib_generic_swap(&x, &y, sizeof(float));
    printf("X : %f  y : %f \n", x, y);
    printf("a : %d b : %d \n", a, b);
    bclib_generic_swap(&a, &b, sizeof(int));
    printf("a : %d b : %d \n", a, b);
    printf("dval1 : %f  dval2 : %f \n", dval1, dval2);
    bclib_generic_swap(&dval1, &dval2, sizeof(double));
    printf("dval1 : %f  dval2 : %f \n", dval1, dval2);
   
}


void genericReverseTestFunc()
{

    int dizi[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        dizi[i] = i;
    }
    bclib_print_array(dizi, SIZE);
    bclib_reverse(dizi, SIZE, sizeof(int));
    printf("\n Reverse \n ");
    bclib_print_array(dizi, SIZE);

    printf("\n");

    double arr[SIZE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1,11.1,12.2,13.3,14.4,15.5,16.6,17.7,18.8,19.9,20.2345 };
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%.2f ", arr[i]);

    }
    bclib_reverse(arr, SIZE, sizeof(double));
    printf("\n");
    printf("\n Reverse \n ");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%.2f ", arr[i]);

    }
}
void bclib_memchr_test_func(void)
{
    int arr[SIZE];
    for (size_t i = 20; i > 0; --i)
    {

        arr[SIZE - i] = i;

    }
    bclib_print_array(arr, SIZE);
    bclib_buble_sort(arr, SIZE);
    printf("\n\n");
    bclib_print_array(arr, SIZE);
    printf("\n");
    int* ptr = (int*)bclib_memchr(arr, 21, SIZE);
    if (!ptr)
    {
        printf("Bu deger yok ! \n");
    }
    else
    {
        printf("%d degeri %d . indiste. \n", *ptr, ptr - arr);
    }
}

void print_double_array(double double_array[], int size) {
    printf("Double Array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %.2lf\n", i, double_array[i]);
    }
}
void print_float_array(float float_array[], int size) {
    printf("Float Array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %.2f\n", i, float_array[i]);
    }
}

int main()
{
    double double_array[20];

    // Diziye değer atama
    for (int i = 0; i < 20; i++) {
        double_array[i] = rand() * 1.1; // Örnek değerler
    }
    float float_array[20];

    // Diziye değer atama
    for (int i = 0; i < 20; i++) {
        float_array[i] = rand() * 1.1f; // Örnek değerler
    }
    bclib_random();
    int arr[SIZE] = { 0 };
    for (size_t i = 0; i < SIZE; ++i)
    {   
        arr[i] = rand();

    }
    bclib_print_array(arr, SIZE);
    bclib_sort_array(arr, SIZE, sizeof(int),bclib_qsort_int_cb);
    printf("\n Sorted : \n  ");
    bclib_print_array(arr, SIZE);
    printf("\n \n  ");
    print_double_array(double_array, SIZE);
    printf("\n Sorted : \n  ");
    bclib_sort_array(double_array, SIZE, sizeof(double), bclib_qsort_double_cb);
    print_double_array(double_array, SIZE);
    print_float_array(float_array, SIZE);
    bclib_sort_array(float_array, SIZE, sizeof(float), bclib_qsort_float_cb);
    printf("\n Sorted : \n  ");
    print_float_array(float_array, SIZE);

    printf("\n Sorted : \n  ");

    char str[SIZE] = "Berkay";
    puts(str);
    bclib_strcat(str, " uzun");
    puts(str);
    printf("Size : %d ", bclib_strlen(str));




}

