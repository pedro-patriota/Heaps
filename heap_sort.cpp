#include <iostream>
using namespace std;

class HeapSort
{
private:
    int capacity;
    int heap_size;

public:
    int *harr; // heap array

    HeapSort(int *arr, int my_capacity, int size); // Constructor

    void build_heap(); // Builds the heap from the array

    void bubble_down(int position); // Moves the value down

    void sort(); // Sorts the array

    int heap_extract(); // Removes the largest value
};

HeapSort ::HeapSort(int *arr, int my_capacity, int size) // Constructor
{
    harr = arr;
    capacity = my_capacity;
    heap_size = size;
}

void HeapSort ::build_heap()
{
    for (int i = int(heap_size / 2 - 1); i != -1; i--)
    {
        bubble_down(i); // Moves each sub parent value to its respective position
    }
}

void HeapSort ::bubble_down(int position)
{
    int l, r, m;
    l = 2 * position + 1;
    r = 2 * position + 2;
    m = position;

    if (l < heap_size && harr[l] >= harr[m]) // Bubble_down's logic
    {
        m = l;
    }
    if (r < heap_size && harr[r] >= harr[m])
    {
        m = r;
    }
    if (m != position) // If "m" changes
    {
        int temp = harr[m]; // Permutation

        harr[m] = harr[position];
        harr[position] = temp;

        return bubble_down(m); // Recursive
    }
    return;
}

int HeapSort ::heap_extract()
{
    int r = harr[0]; // Gets the largest value

    int temp = harr[heap_size - 1]; // Permutation
    harr[heap_size - 1] = harr[0];
    harr[0] = temp;

    heap_size = heap_size - 1;
    bubble_down(0); // Makes the leaf to move down
    return r;
}

void HeapSort ::sort()
{
    build_heap();

    while (heap_size > 1)
    {
        heap_extract(); // Extracts each sub maximum
    }
}

int main()
{
    int *arr = new int[5];
    arr[0] = 0;
    arr[1] = 9;
    arr[2] = 7;
    arr[3] = 2;
    arr[4] = 3;

    HeapSort heap(arr, 5, 5);
    heap.sort();

    for (int i = 0; i < 5; i++)
    {
        cout << heap.harr[i] << " ";
    }

    delete[] heap.harr; // Deletes each pointer
    delete[] arr;
    return 0;
}
