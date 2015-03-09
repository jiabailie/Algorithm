#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
	void reverse(int nums[], int s, int e) {
		for(int i = s, j = e; i < j; ++i, --j) {
			std::swap(nums[i], nums[j]);
		}
	}
    void rotate(int nums[], int n, int k) {
		k %= n;
        reverse(nums, 0, n);
		reverse(nums, 0, k);
		reverse(nums, k, n);
    }
};

int main()
{	
	int k = 3;
	int n = 7;

	int nums[] = {1,2,3,4,5,6,7};

	Solution sol;

	sol.rotate(nums, n, k);

	for(int i = 0; i < n; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}