/**
 * Longest Increasing Subsequence problem
 * Description: en.wikipedia.org/wiki/Longest_increasing_subsequence
 */
#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <Windows.h>
#define DEBUG
#undef  DEBUG

const int len = 19797;

int dp[len];
char str[len];

inline void display()
{
#ifdef DEBUG
    for(int i = 0; i < len; ++i)
    {
        std::cout << dp[i] << " ";
    }
    std::cout << std::endl;
#endif
}

inline int imax(int a, int b)
{
    return a > b ? a : b;
}

/* The most simple idea, O(n^2). */
inline int solve1()
{
    int i = 0, j = 0;

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for(i = 1; i < len; ++i)
    {
        dp[i] = 1;
        for(j = 0; j < i; ++j)
        {
            if(str[j] <= str[i])
            {
                dp[i] = imax(dp[i], dp[j] + 1);
            }
        }
    }

    display();

    return dp[len - 1];
}

/* Improve solution 1, still O(n^2). */
inline int solve2()
{
    int i = 0, j = 0;
    memset(dp, 0, sizeof(dp));

    for(i = 0; i < len - 1; ++i)
    {
        if(dp[i] == 0)
        {
            dp[i] = 1;
        }
        for(j = i + 1; j < len; ++j)
        {
            if(str[i] <= str[j])
            {
                dp[j] = imax(dp[i] + 1, dp[j]);
            }
        }
    }

    display();

    return dp[len - 1];
}

/* O(k * n), here is O(26 * n). */
/* tail[i] = max length{ sub-strings which use char(i) as its tail. } */
inline int solve3()
{
    int i = 0, j = 0;

    int tail[26];

    memset(dp, 0, sizeof(dp));
    memset(tail, 0, sizeof(tail));

    dp[0] = 1;
    tail[int(str[0] - 'a')] = 1;

    for(i = 1; i < len; ++i)
    {
        dp[i] = 1;

        for(j = 0; j <= int(str[i] - 'a'); ++j)
        {
            if(tail[j] + 1 > dp[i])
            {
                dp[i] = tail[j] + 1;
            }
        }

        if(dp[i] > tail[int(str[i] - 'a')])
        {
            tail[int(str[i] - 'a')] = dp[i];
        }
    }

    display();

    return dp[len - 1];
}

int main()
{
    int i = 0;
    DWORD t1 = 0, t2 = 0, t3 = 0;
    for(i = 0; i < len; ++i)
    {
        str[i] = char('a' + (rand() % 26));
    }

    std::cout << std::string(str, str + len).c_str() << std::endl;

    DWORD start_time = GetTickCount();

    std::cout << "solve 1 = " << solve1() << std::endl;

    DWORD end_time = GetTickCount();

    t1 = end_time - start_time;

    std::cout << std::endl;

    start_time = GetTickCount();

    std::cout << "solve 2 = " << solve2() << std::endl;

    end_time = GetTickCount();

    t2 = end_time - start_time;

    std::cout << std::endl;

    start_time = GetTickCount();

    std::cout << "solve 3 = " << solve3() << std::endl;

    end_time = GetTickCount();

    t3 = end_time - start_time;

    std::cout << t1 << " " << t2 << " " << t3 << std::endl;

    return 0;
}