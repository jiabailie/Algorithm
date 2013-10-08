#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

inline void swap(int& a, int& b) { int t = a; a = b; b = t; }

void adjustHeap(int pos, int* arrayA)
{
    int max = 0;
    int left = 0;
    int right = 0;
    for(int i = pos / 2; i >= 0; i--)
    {
        max = i;
        left = 2 * i + 1;
        right = 2 * i + 2;
        if(left <= pos && arrayA[left] > arrayA[max]) { max = left; }
        if(right <= pos && arrayA[right] > arrayA[max]) { max = right; }
        if(max != i) { swap(arrayA[i], arrayA[max]); }
    }
}

void heapSort(int lenA, int* arrayA)
{
    if(lenA == 0)
    {
        return;
    }
    for(int i = lenA - 1; i > 0; i--)
    {
        adjustHeap(i, arrayA);
        swap(arrayA[0], arrayA[i]);
    }
}

void putElementToMinHeap(int data, int lenA, int* arrayA)
{
    if(data > arrayA[0])
    {
        arrayA[0] = data;
        int min = 0;
        int pos = 0;
        int left = 1;
        int right = 2;

        while(true)
        {
            min = pos;
            left = 2 * pos + 1;
            right = 2 * pos + 2;
            if(left < lenA && arrayA[left] < arrayA[min]) { min = left; }
            if(right < lenA && arrayA[right] < arrayA[min]) { min = right; }

            if(pos == min) { break; }
            else if(pos != min)
            {
                swap(arrayA[pos], arrayA[min]);
                pos = min;
            }
        }
    }
}

int findKthMaxNumber(int k, int lenA, int* arrayA)
{
    int i = 0;
    int* heap = new int[k];
    for(i = 0; i < k; i++)
    {
        heap[i] = arrayA[i];
    }
    heapSort(k, heap);
    for(i = k; i < lenA; i++)
    {
        putElementToMinHeap(arrayA[i], lenA, arrayA);
    }
    return heap[0];
}

int main()
{
    int d[10] = {9, 8, 7, 3, 4, 6, 1, 2, 3, 0};
    int* a = d;

    cout << findKthMaxNumber(5, 10, a);

    return 0;
}
