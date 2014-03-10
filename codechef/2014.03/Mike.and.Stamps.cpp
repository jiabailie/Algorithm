#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n = 0;
int m = 0;
int amount[20];
bool board[20][20];
int maxAmount = 0;
int maxBuyers = 0;
vector<vector<int> > buyers;

inline bool hasNothingInterect(vector<int>& a, vector<int>& b)
{
	int i = 0, j = 0;
	int la = a.size();
	int lb = b.size();
	if(a[0] > b[lb - 1] || b[0] > a[la - 1])
	{
		return true;
	}

	for(i = 0; i < la; i++)
	{
		for(j = 0; j < lb; j++)
		{
			if(a[i] == b[j])
			{
				return false;
			}
		}
	}
	return true;
}

inline void judgeStep(int cur, int sold, int selected, bool select[20])
{
	if(cur == m)
	{
		if(sold > maxAmount)
		{
			maxAmount = sold;
			maxBuyers = selected;
		}
		else if(sold == maxAmount && selected > maxBuyers)
		{
			maxBuyers = selected;
		}
		return;
	}

	// selected
	int i = 0;
	for(i = 0; i < cur; ++i)
	{
		if(select[i] && !board[i][cur])
		{
			break;
		}
	}
	if(i == cur)
	{
		select[cur] = true;
		judgeStep(cur + 1, sold + amount[cur], selected + 1, select);
	}

	// not selected
	select[cur] = false;
	judgeStep(cur + 1, sold, selected, select);
}

int main()
{
	int i = 0, j = 0;
	int k = 0, t = 0;
	scanf("%d %d", &n, &m);

	buyers.clear();

	memset(amount, 0, sizeof(amount));
	memset(board, false, sizeof(board));

	for(i = 0; i < m; ++i)
	{
		scanf("%d", &k);
		vector<int> tmp;
		for(j = 0; j < k; ++j)
		{
			scanf("%d", &t);
			tmp.push_back(t);
		}
		amount[i] = k;
		sort(tmp.begin(), tmp.end());
		buyers.push_back(tmp);
	}
	
	for(i = 0; i < m - 1; ++i)
	{
		for(j = i + 1; j < m; ++j)
		{
			if(hasNothingInterect(buyers[i], buyers[j]))
			{
				board[i][j] = true;
				board[j][i] = true;
			}
		}
	}

	bool f[20];
	judgeStep(0, 0, 0, f);

	printf("%d\n", maxBuyers);

	return 0;
}