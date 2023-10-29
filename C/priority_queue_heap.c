#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 10

//definition of a heap 
struct heap {
    int size;
    int capacity;
    int *data; //array of heap elements
};

struct heap *create_heap (int capacity)
{
    //allocate memory for teh heap
    struct heap *heap = malloc(sizeof(struct heap));
    heap->size = 0; 
    heap->capacity = capacity; 
    //allocate memory for the array of heap elements
    heap->data = malloc(capacity *sizeof(int));
    return heap; 
}

void destroy_heap(struct heap *heap)
{
    if (heap == NULL)
    {
        return;
    }
    //free memory for the array of heap elements
    free(heap->data);
    //free memory for the heap
    free(heap);
}

int parent(int index)
{
    return (index -1) /2;
}

int left_child(int index)
{
    return 2 * index + 1;
}

int right_child(int index)
{
    return 2 * index + 2;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void heapify_up(struct heap *heap, int index)
{
    //as long as current is smaller than its parent
    while (index > 0 && heap->data[parent(index)] > heap->data[index])
    {
        //swap current with parent
        swap(&heap->data[parent(index)], &heap->data[index]);
        
        //udpate the index to parent
        index = parent(index);
    }
}

void heapify_down(struct heap *heap, int index)
{
    //initialize the index of minimum value to the current node
    int min_index = index;

    //check if left child exists and is smaller than the current node
    int left = left_child(index);
    if(left < heap->size && heap->data[left] < heap->data[min_index])
    {
        min_index = left;
    }

    //check if right child exists and is smaller than current minium value
    int right = right_child(index);
    if (right < heap->size && heap->data[right] < heap->data[min_index])
    {
        min_index = right; 
    }

    //if the minium value is not current node, swap the values and continue heapifying down
    if (index != min_index)
    {
        swap(&heap->data[index], &heap->data[min_index]);
        heapify_down(heap, min_index);
    }
}

//insert value to heap
void insert(struct heap *heap, int value)
{
    //check if heap is full
    if (heap->size == heap->capacity)
    {
        return; 
    }
    heap->data[heap->size] = value;
    
    //increase size of the heap
    heap->size++;

    //heapify the new value up the heap
    heapify_up(heap, heap->size -1);
}

int extract_min (struct heap *heap)
{
    //return if empty
    if(heap->size = 0)
    {
        return -1; 
    }

    //save minium value to return later; 
    int min = heap->data[0];

    //swap the first and last values in the heap
    swap(&heap->data[0], &heap->data[heap->size -1]);

    //decrease size of heap
    heap->size--;

    //heapify new value down the heap
    heapify_down(heap, 0); 

    return min; 
}

int main()
{
    struct heap *heap = create_heap(HEAP_SIZE);

    // insert value
    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 1);

    int min = extract_min(heap);
    
    printf("Minimum value: %d\n", min);

    destroy_heap(heap);

    return 0;
}

