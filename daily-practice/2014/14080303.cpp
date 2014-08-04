#include <cstdio>
#include <iostream>

using namespace std;

typedef int (*fun)(int);

class Add
{
private:
	static int N;
	static int Sum;
public:
	Add() { ++N; Sum += N; }

	static void Reset() { N = 0; Sum = 0; }
	static int GetSum() { return Sum; }
};

int Add::N = 0;
int Add::Sum = 0;

int solution1(int n)
{
	Add::Reset();

	Add *a = new Add[n];
	delete []a;
	a = 0;

	return Add::GetSum();
}

template<int n> struct solution2
{
	enum Value { N = solution2<n - 1>::N + n };
};

template <> struct solution2<1>
{
	enum Value { N = 1 };
};

int solution3_f1(int num)
{
	return 0;
}

int solution3_f2(int num)
{
	fun f[2] = { solution3_f1, solution3_f2 };
	return num + f[!!num](num - 1);
}

int main()
{
	cout << solution3_f2(100) << endl;
	return 0;
}