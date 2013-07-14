/*
  Given a sorted array, write a function to search first occurrence of a number in the array. If not found return -1.
  Example::
  {2,2,2,3,4,5,5,6,6,8,9}
  search 6
  should return 7.
*/
#include <cstdio>
#include <iostream>
using namespace std;

int binarySearch(int start, int end, int key, int data[])
{
    int mid = start + (end - start) / 2;
    int left = start;
    int right = end;
    int ret = -1;
    if(data == NULL || start < 0 || end < 0 || start > end || key < data[0] || key > data[end])
    {
        return -1;
    }
    while(true)
    {
        mid = left + (right - left) / 2;
        if(data[mid] == key)
        {
            int t = binarySearch(start, mid - 1, key, data);
            ret = t == -1 ? mid : t;
            break;
        }
        if(data[mid] < key)
        {
            left = mid + 1;
        }
        if(data[mid] > key)
        {
            right = mid - 1;
        }
        if(left > right)
        {
            ret = -1;
            break;
        }
    }
    return ret;
}

int main()
{
    int data[11] = {2,2,2,3,4,5,5,6,6,8,9};
    int f = 6;

    cout << binarySearch(0, 10, 6, data) << endl;

    return 0;
}
