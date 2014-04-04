#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

class GearsDiv2
{
public:
	int getmin(string Directions);
};

int GearsDiv2::getmin(string Directions)
{
	int i = 0, k = 0;
    int n = Directions.size();
    int min = 0;
    int cnt[51];

    cnt[0] = 1;

    for (i = 1; i < n; ++i)
    {
        if (Directions[i] == Directions[i - 1])
        {
            cnt[k] += 1;
        }
        else
        {
            k += 1;
            cnt[k] = 1;
        }
    }

    if (k == 0)
    {
        return (cnt[0] + 1) / 2;
    }

    for (i = 1; i < k; ++i)
    {
        if (cnt[i] > 1)
        {
            min += cnt[i] / 2;
        }
    }

    if (Directions[0] == Directions[n - 1])
    {
        min += (cnt[0] + cnt[k]) / 2;
    }
    else
    {
        min += (cnt[0] / 2) + (cnt[k] / 2);
    }

    return min;
}