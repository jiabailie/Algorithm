#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findIntersection(vector<int>& A, vector<int>& B)
{
	vector<int> ret;
	int curA = 0, curB = 0;
	while(curA < A.size() && curB < B.size())
	{
		if(A[curA] == B[curB])
		{
			ret.push_back(A[curA]);
			curA += 1;
			curB += 1;
		}
		else if(A[curA] < B[curB])
		{
			curA += 1;
		}
		else if(A[curA] > B[curB])
		{
			curB += 1;
		}
	}
	return ret;
}

int main()
{
	int i = 0;
	vector<int> A(100, 0);
	vector<int> B(200, 0);

	for(i = 0; i < A.size(); ++i)
	{
		A[i] = (rand() * rand() + rand() * 4) % 567;		
	}
	sort(A.begin(), A.end());
	for(i = 0; i < A.size(); ++i)
	{
		B[i] = (rand() * rand() + rand() * 5) % 567;
	}
	sort(B.begin(), B.end());
	vector<int> ret = findIntersection(A, B);
	for(i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << " ";
	}
	cout << endl;

	return 0;
}