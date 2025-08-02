#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

#define ARRAY_SIZE 1024 /// 1024, 4096, 8192, etc

#define BUBBLE_SORT     1
#define SELECTION_SORT  2
#define INSERTION_SORT  3
#define MERGE_SORT      4

void print_array(int * ptr_array, int size);
void sort_array(int * ptr_array, int size, int sort_type);
void merge_sort_array(int * ptr_array, int size);
void merge(int * ptr_array, int left, int mid, int right);

int main()
{
    srand((unsigned int)time(NULL));    /// Random number generator seeded with the value of time

    /** Initialize an Integer Array and initialize it with random numbers between 0-255 **/
    wint_t my_array[ARRAY_SIZE];

    for(int i=0; i<ARRAY_SIZE; i++)
    {
        my_array[i] = rand()%256;
    }
    /*************************************************************************************/
    print_array(my_array, ARRAY_SIZE);
    printf("\n\n");

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    /// do the sorting part here
    sort_array(my_array, ARRAY_SIZE, BUBBLE_SORT);

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);

    print_array(my_array, ARRAY_SIZE);

    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("\n\nTime measured: %f Seconds.\n", elapsed);
    printf("\nTime measured: %lu Microseconds.\n", microseconds);

    return 0;
}

void print_array(int * ptr_array, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%3d\t", *(ptr_array+i));
    }
}

void sort_array(int * ptr_array, int arr_size, int sort_type)
{
    switch(sort_type)
    {
        case BUBBLE_SORT:
            // Bubble Sort Implementation (Already provided)
            for(int k = arr_size; k>0; k--)
            {
                for(int i=0; i<k-1; i++)
                {
                    if(*(ptr_array+i)>*(ptr_array+i+1))
                    {
                        int temp = *(ptr_array+i+1);
                        *(ptr_array+i+1) = *(ptr_array+i);
                        *(ptr_array+i) = temp;
                    }
                }
            }
            break;

        case SELECTION_SORT:
            // Selection Sort Implementation
            for (int i = 0; i < arr_size - 1; i++)
            {
                int min_index = i;
                for (int j = i + 1; j < arr_size; j++)
                {
                    if (*(ptr_array + j) < *(ptr_array + min_index))
                    {
                        min_index = j;
                    }
                }
                // Swap the found minimum element with the first element
                int temp = *(ptr_array + min_index);
                *(ptr_array + min_index) = *(ptr_array + i);
                *(ptr_array + i) = temp;
            }
            break;

        case INSERTION_SORT:
            // Insertion Sort Implementation
            for (int i = 1; i < arr_size; i++)
            {
                int key = *(ptr_array + i);
                int j = i - 1;

                while (j >= 0 && *(ptr_array + j) > key)
                {
                    *(ptr_array + j + 1) = *(ptr_array + j);
                    j = j - 1;
                }
                *(ptr_array + j + 1) = key;
            }
            break;

        case MERGE_SORT:
            // Merge Sort Implementation
            merge_sort_array(ptr_array, arr_size);
            break;
    }
}

void merge_sort_array(int * ptr_array, int size)
{
    if (size > 1)
    {
        int mid = size / 2;
        merge_sort_array(ptr_array, mid);
        merge_sort_array(ptr_array + mid, size - mid);
        merge(ptr_array, 0, mid, size);
    }
}

void merge(int * ptr_array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = *(ptr_array + left + i);
    for (j = 0; j < n2; j++)
        R[j] = *(ptr_array + mid + 1 + j);

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {   *(ptr_array + k) = L[i];
            i++;}
        else
        {   *(ptr_array + k) = R[j];
            j++;}
        k++;
    }
    while (i < n1)
    {   r_array + k) = L[i];
        i++;
        k++;  }
    while (j < n2)
    {*(ptr_array + k) = R[j];
        j++;
        k++;} }

