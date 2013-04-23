/*
 *There is large set of sorted data where number of data is not known.
 *How could a given number be find efficiently?
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#define MAX 1000

using namespace std;

/*
 * return the index of the element in data
 * or -1 if it doesn't exist
 */
int find(int target, int *data)
{
    int start = 0;
    int end = 1;
    int ret = -1;
    int find = 0;
    while(!find)
    {
        if(target <= data[end])
        {
            /* do binary search in this range */
            int s = start;
            int e = end;

            while(!find)
            {
                int mid = start + (end - start) / 2;
                if(data[mid] == target) { ret = mid; find = 1; }
                else if(data[mid] < target) { s = mid + 1; }
                else if(data[mid] > target) { e = mid - 1; }
                if(s > e) { find = 1; }
            }
        }
        /* if target isn't in this range data[start,...,end], then change the range to data[end + 1,...,end * 2 + 1] */
        else
        {
            start = end + 1;
            end = end * 2 + 1;
        }
    }
    return ret;
}

int main()
{
    int i = 0;
    int target = 0;
    int *data = (int*)malloc(sizeof(int) * MAX);
    while(scanf("%d", &data[i++]) != EOF);
    scanf("%d", &target);
    printf("%d\n", find(target, data));
    return 0;
}
