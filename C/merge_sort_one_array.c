#include <stdio.h>

void merge_sort(int *array, int size)
{
    //if size is less than 2, already sorted
    if (size < 2) return;

    int mid = size/2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++) left[i] = array[i];
    for (int i = 0; i < size - mid; i++) right[i] = array[mid + i];

    //recursively sort two halves
    merge_sort(left, mid);
    merge_sort(right, size - mid); 

    //merge two halves back
    merge(array, left, right, size-mid);
}

void merge(int *result, int *left, int left_size, int *right, int right_size)
{
    int left_index = 0;
    int right_index = 0;
    int result_index = 0;

    while(left_index < left_size && right_index < right_size)
    {
        if (left[left_index] < right[right_index])
        {
            result[result_index] = left[left_index];
            left_index++;
        }
        else
        {
            result[result_index] = right[right_index];
            right_index++;
        }
        result_index++;
    }

    //if one of the lists is non-empty, append all of its elements to the result array
    for (int i = left_index; i < left_size; i++) result[result_index++] = left[i];
    for (int i = right_index; i < right_size; i++) result[result_index++] = right[i]; 
}

int main()
{
    int array[] = {5,2,4,7,1,3,2,6};
    int size = sizeof(array) / sizeof(array[0]);

    merge_sort(array, size);

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}