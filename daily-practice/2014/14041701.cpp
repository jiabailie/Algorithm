/**
 * Description: 
 * If there are an integer array, and there is a positive number x.
 * Find the maximum ways to do sum to get x.
 * eg. array = [1, 2, 3], x = 3
 * s.  2 ways, [1, 2] and [3]
 * Analysis:
 * If I can use minimum elements to get x, then repeat the search to find the minimum items to get x.
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define DEBUG

const int MAX = 100;

int cnt = 0;
int sum = 0;
int dp[MAX];
std::vector<int> data;
std::vector<bool> used;

std::vector<int> readData()
{
    int x = 0;
    std::vector<int> data;

    std::cout << "Please input the array:" << std::endl;

#ifdef DEBUG
    std::cout << "The data array is:" << std::endl;
    for(int i = 0; i < 30; ++i)
    {
        x = rand() % 10;
        if(x <= 0)
        {
            x += 1;
        }
        data.push_back(x);
    }
#else
    while((std::cin >> x) && (x > 0))
    {
        data.push_back(x);
    }
#endif
    return data;
}

void search(int s)
{
    int i = 0, j = 0;
    for(i = 0; i < MAX; ++i)
    {
        dp[i] = - 1;
    }

    dp[sum - data[s]] = s;
    for(i = s - 1; i >= 0 && dp[0] == -1; --i)
    {
        if(used[i]) { continue; }
        for(j = sum - data[s]; j >= 0 && dp[0] == -1; --j)
        {
            if(dp[j] != -1 && dp[j] != i && j - data[i] >= 0 && dp[j - data[i]] == -1)
            {
                dp[j - data[i]] = i;
            }
        }
    }
    if(dp[0] != -1)
    {
        cnt += 1;
        for(i = 0; i < sum ; i += data[dp[i]])
        {
            used[dp[i]] = true;
            std::cout << data[dp[i]] << " ";
        }
        std::cout << std::endl;
    }
}

void solve()
{
    int i = 0;
    int n = int(data.size());
    std::sort(data.begin(), data.end());
#ifdef DEBUG
    for(std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;
#endif

    for(i = n - 1; i >= 0 && data[i] > sum; --i);
    for(; i >= 0; --i)
    {
        if(!used[i])
        {
            search(i);
        }
    }
}

int main()
{
    data = readData();

#ifdef DEBUG
    sum = 10;
#else
    std::cout << "Please input the sum you want to get:" << std::endl;
    
    std::cin >> sum;
#endif
    used = std::vector<bool>(data.size(), false);

    solve();

    std::cout << "There are " << cnt << " ways to get " << sum << "." << std::endl;

    return 0;
}