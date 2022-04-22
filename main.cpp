#include <iostream>
using namespace std;

class MaxHeap // MaxHeap
{
private:
    int capacity;
    int heap_size;

public:
    int *harr;
    MaxHeap(int my_capacity); // Constructor

    int parent(int i) // Gets the parent
    {
        return (int)(i - 1) / 2;
    }

    void heap_insert(int val); // Inserts

    void bubble_up(int position); // Moves the value up

    void bubble_down(int position); // Moves the value down

    int heap_extract(); // Removes the largest value
};

MaxHeap ::MaxHeap(int my_capacity)
{
    capacity = my_capacity;
    heap_size = 0;
    harr = new int[capacity];
}

void MaxHeap ::heap_insert(int val)
{
    if (capacity == heap_size) // If the heap is full
    {
        cout << "full\n";
        return;
    }
    harr[heap_size] = val;
    bubble_up(heap_size); // Inserts the value in the end of the heap and moves it up
    heap_size++;
    return;
}

void MaxHeap ::bubble_up(int position)
{
    int i = position;
    while (i > 0 && harr[i] >= harr[parent(i)]) // Maxheap logic
    {
        int temp = harr[parent(i)]; // Permutation
        harr[parent(i)] = harr[i];
        harr[i] = temp;

        i = parent(i); // The "while" will now analyze the new position of the value
    }
    return;
}

void MaxHeap ::bubble_down(int position)
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

int MaxHeap ::heap_extract()
{
    int r = harr[0]; // Gets the largest value

    int temp = harr[heap_size - 1]; // Permutation
    harr[heap_size - 1] = harr[0];
    harr[0] = temp;

    heap_size = heap_size - 1;
    bubble_down(0); // Makes the leaf to move down
    return r;
}

int main()
{
    MaxHeap max(10);
    max.heap_insert(21);
    max.heap_insert(12);
    max.heap_insert(90);
    max.heap_insert(700);
    max.heap_insert(5);
    max.heap_insert(122);
    max.heap_insert(1);
    int r = max.heap_extract();
    cout << r; // 700

    delete max.harr; // Deletes the pointer
    return 0;
}
