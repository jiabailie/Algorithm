/**
 * There is an integer array d which does not contain more than two elements of the same value. 
 * How many distinct ascending triples (d[i] < d[j] < d[k], i < j < k) are present?
 * Input format:
 * The first line contains an integer N denoting the number of elements in the array. 
 * This is followed by a single line containing N integers separated by a single space with no leading/trailing spaces
 *
 * Output format:
 * A single integer that denotes the number of distinct ascending triples present in the array
 *
 * Constraints:
 * N <= 10^5 Every value in the array is present at most twice Every value in the array is a 32-bit positive integer
 *
 * Sample input:
 * 6 
 * 1 1 2 2 3 4
 * Sample output:
 * 4
 * Explanation:
 * The distinct triplets are
 * (1,2,3)
 * (1,2,4)
 * (1,3,4)
 * (2,3,4)

 * Another test case:
 * Input:
 * 10
 * 1 1 5 4 3 6 6 5 9 10
 * Output:
 * 28
 *
 * References: stackoverflow.com/questions/13928575/interviewstreet-triplet-challenge
 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
int CalTriples(int len, vector<int> &numbers)
{
	int i = 0, j = 0;
	int triples = 0;
	vector<int> noDuplicate;

	/* Remove duplicate consistence elements. */
	for(i = 0; i < len; ++i)
	{
		noDuplicate.push_back(numbers[i]);
		if(i + 1 < len && numbers[i] == numbers[i + 1])
		{
			i += 1;
		}
	}

	len = noDuplicate.size();

	if(len < 3) { return 0; }

	vector<int> less(len, 0);
	vector<int> larger(len, 0);
	set<int> diffSet;

	// From left to right, calculating the elements amount which are less than element[i].
	for(i = 1; i < len; ++i)
	{
		diffSet.clear();
		for(j = i - 1; j >= 0; --j)
		{
			// If this number has appeared before this position, don't repeat the appearance times the number before it.
			if(noDuplicate[j] == noDuplicate[i])
			{
				break;
			}
			if(noDuplicate[j] < noDuplicate[i])
			{
				diffSet.insert(noDuplicate[j]);
			}
		}
		less[i] = diffSet.size();
	}

	// From right to left, calculating the elements amount which is larger than element[i].
	for(i = len - 2; i >= 0; --i)
	{
		diffSet.clear();
		for(j = i + 1; j < len; ++j)
		{
			if(noDuplicate[i] < noDuplicate[j])
			{
				diffSet.insert(noDuplicate[j]);
			}
		}
		larger[i] = diffSet.size();
	}

	for(i = 0; i < len; ++i)
	{
		triples += less[i] * larger[i];
	}
	return triples;
}
/* The general method to find the difference triples. */
int CalTriplesGeneral(int len, vector<int> &numbers)
{
	int i = 0, j = 0, k = 0;
	int triples = 0;
	set<int> setTriples;
	for(i = 0; i <= len - 3; ++i)
	{
		for(j = i + 1; j <= len - 2; ++j)
		{
			for(k = j + 1; k <= len - 1; ++k)
			{
				if(numbers[i] < numbers[j] && numbers[j] < numbers[k])
				{
					setTriples.insert(numbers[i] * 10000 + 100 * numbers[j] + numbers[k]);
				}
			}
		}
	}
	return setTriples.size();
}
int main()
{
	int len = 10;

	int numbers[] = {1, 1, 5, 4, 3, 6, 6, 5, 9, 10};

	vector<int> vecNum(numbers, numbers + sizeof(numbers) / sizeof(int));

	int triples1 = CalTriplesGeneral(len, vecNum);
	int triples2 = CalTriples(len, vecNum);

	cout << triples1 << " " << triples2 << endl;

	return 0;
}