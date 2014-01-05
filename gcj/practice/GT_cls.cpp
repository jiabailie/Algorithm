#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;     

//swap the value a and b
inline void swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

//adjust the heap
void heapUp(int a[], int i, int n)
{
    int j = 0;
    int p = 0;
    while(i > 0)
    {
       j = ((i & 1) == 0 ? i - 1 : i + 1);
       p = (i - 1) >> 1;
       if(j < n && a[j] < a[i])
	   {
		   i = j;
	   }
	   if(a[i] < a[p])
       {
           swap(a[i], a[p]);
       }
       i = p;
     }
}

int main()
{
	int i = 0;
	int j = 0;
    int k = 0;
    int n = 0;
    int res = 0;
    int* data = NULL;

    cin >> n >> k;
    data = new int[n];
      
    for(i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	for(j = 0; j < k; j++)
	{
		for(i = n - 1; i >= 0; i--)
		{
			heapUp(data, i, n);
		}
		if(j < k - 1)
		{
			data[0] = (1 << 30);
		}
	}
	res = data[0];
	return 0;
}
