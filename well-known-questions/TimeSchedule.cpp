/*
 * Description: There are n tasks, task[i] starts at s[i], and ends at t[i]. 
 * If you choose task[i], you should finish it, which means you can't quit in the process.
 * Every two tasks can't be overlapped. How many tasks you can finish try you best?
 * n = 5;
 * s[n] = {1, 2, 4, 6, 8};
 * t[n] = {3, 5, 7, 9, 10};
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct segment
{
	int s;
	int e;
	segment(int _s, int _e) : s(_s), e(_e) {}
};

inline void iswap(int& a, int& b) { int c = a; a = b; b = c; }

inline void iswap(segment& a, segment& b) { iswap(a.e, b.e); iswap(a.s, b.s); }

inline int left(int p) { return (p << 1) + 1; }

inline int right(int p) { return ((p + 1) << 1); }

inline void adjust(int len, vector<segment>& timetable)
{
	int i = 0;
	int m = 0, l = 0, r = 0;
	for(i = (len + 1) >> 1; i >= 0; i--)
	{
		m = i;
		l = left(i);
		r = right(i);

		if(l < len && timetable[l].e > timetable[m].e) { m = l; }
		if(r < len && timetable[r].e > timetable[m].e) { m = r; }
		if(i != m) { iswap(timetable[i], timetable[m]); }
	}
}

inline void isort(vector<segment>& timetable)
{
	int len = timetable.size();
	for(int i = len; i > 0; i--)
	{
		adjust(i, timetable);
		iswap(timetable[0], timetable[i - 1]);
	}
}

int main()
{
	const int n = 5;
	int i = 0, j = 0;
	int cnt = 0, lt = 0;
	int s[n] = {1, 2, 4, 6, 8};
	int t[n] = {3, 5, 7, 9, 10};
	vector<segment> timetable;

	for(int i = 0; i < n; i++)
	{
		timetable.push_back(segment(s[i], t[i]));
	}
	isort(timetable);

	for(i = 0; i < n; i++)
	{
		if(timetable[i].s >= lt)
		{
			cnt++;
			lt = timetable[i].e;
		}
	}

	cout << cnt << endl;
	return 0;
}