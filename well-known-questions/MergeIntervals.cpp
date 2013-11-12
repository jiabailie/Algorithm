/*
 * References : mp.weixin.qq.com/mp/appmsg/show?__biz=MjM5ODIzNDQ3Mw==&appmsgid=10000320&itemidx=1&sign=294a7eb699269491d5836a6ebf9adf62#wechat_redirect
 */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

inline int LEFT(int n) { return (n << 1) + 1; }

inline int RIGHT(int n) { return (n + 1) << 1; }

template<typename T>
inline T imax(T a, T b) { return a > b ? a : b; }

template<typename T>
inline T imin(T a, T b) { return a < b ? a : b; }

struct interval
{
	int start;
	int end;
	interval(int _start, int _end) : start(_start), end(_end) {}
	interval(const interval& _interval) : start(_interval.start), end(_interval.end) {}
	interval& operator=(const interval& _interval)
	{
		if(&_interval != this)
		{
			start = _interval.start;
			end = _interval.end;
		}
		return *this;
	}
	bool operator<(const interval& _right) const
	{
		return start < _right.start;
	}
	bool operator>(const interval& _right) const
	{
		return start > _right.start;
	}
};

template<typename T>
inline void iswap(T& a, T& b) { T c = a; a = b; b = c; }

template<typename T>
inline void heapAdjust(int n, vector<T>& heap)
{
	int i = 0, m = 0;
	int l = 0, r = 0;

	for(i = n / 2; i >= 0; i--)
	{
		m = i;
		l = LEFT(i);
		r = RIGHT(i);

		if(l <= n && heap[l] > heap[m]) { m = l; }
		if(r <= n && heap[r] > heap[m]) { m = r; }
		if(m != i) { iswap(heap[i], heap[m]); }
	}
}

template<typename T>
inline void hsort(vector<T>& heap)
{
	for(int i = heap.size() - 1; i >= 0; i--)
	{
		heapAdjust(i, heap);
		iswap(heap[0], heap[i]);
	}
}

inline vector<interval> mergeInterval(const vector<interval>& iset)
{
	int i = 0, n = iset.size();
	int s = 0, e = 0;

	if(n == 0) { return vector<interval>(); }
	if(n == 1) { return vector<interval>(iset.begin(), iset.end()); }

	vector<interval> ret;

	s = iset[0].start;
	e = iset[0].end;

	for(i = 1; i < n; i++)
	{
		if(iset[i].start >= s && iset[i].start <= e) // if current set has overlap with next interval
		{
			e = imax(e, iset[i].end);
		}
		else if(iset[i].start > e) // if current set has no overlap with next interval
		{
			ret.push_back(interval(s, e));
			s = iset[i].start;
			e = iset[i].end;
		}
	}
	ret.push_back(interval(s, e));

	return ret;
}

inline vector<interval> intersecInterval(const vector<interval>& iset)
{
	int i = 0, n = iset.size();
	int s = 0, e = 0, maxE = 0;

	if(n == 0) { return vector<interval>(); }
	if(n == 1) { return vector<interval>(iset.begin(), iset.end()); }

	vector<interval> ret;

	s = iset[0].start;
	e = iset[0].end;
	maxE = iset[0].end;

	for(i = 1; i < n; i++)
	{
		if(iset[i].start >= s && iset[i].start <= e)
		{
			s = imax(s, iset[i].start);
			e = imin(e, iset[i].end);
			maxE = imax(e, iset[i].end);
		}
		else if(iset[i].start > e)
		{
			ret.push_back(interval(s, e));
			s = iset[i].start;
			e = iset[i].end;

			if(iset[i].start <= maxE)
			{
				if(iset[i].end <= maxE)
				{
					ret.push_back(interval(iset[i].start, iset[i].end));
					s = iset[i].end;
					e = maxE;
				}
				else if(iset[i].end > maxE)
				{
					ret.push_back(interval(iset[i].start, maxE));
					s = maxE;
					e = iset[i].end;
					maxE = iset[i].end;
				}
			}
		}
	}
	ret.push_back(interval(s, e));

	return ret;
}

int main()
{
	// [1,3],[2,6],[8,10],[9, 13],[15,18]
	vector<interval> iset;

	iset.push_back(interval(8, 10));
	iset.push_back(interval(2, 6));
	iset.push_back(interval(15, 18));
	iset.push_back(interval(1, 3));
	iset.push_back(interval(9, 13));

	hsort(iset);

	for(vector<interval>::iterator it = iset.begin(); it != iset.end(); it++)
	{
		cout << "[" << (*it).start << " " << (*it).end << "] ";
	}
	cout << endl;

	vector<interval> merge = mergeInterval(iset);

	for(vector<interval>::iterator it = merge.begin(); it != merge.end(); it++)
	{
		cout << "[" << (*it).start << " " << (*it).end << "] ";
	}
	cout << endl;

	vector<interval> intersec = intersecInterval(iset);

	for(vector<interval>::iterator it = intersec.begin(); it != intersec.end(); it++)
	{
		cout << "[" << (*it).start << " " << (*it).end << "] ";
	}
	cout << endl;

	return 0;
}
