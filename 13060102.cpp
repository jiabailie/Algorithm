/*
There are N floors and N persons each one is tagged with some random unique number between 1 to N(represents floor number).
We have a lift which can accommodate one person at a time. Every person is in some random floor.
Initially lift is at floor 1 and all floors have single person.
Problem here is: we have to move the persons to their corresponding floor with minimum number of lift movements.
Restriction : Lift can have at most one person at a time.
While moving persons, at some point of time, we can keep more than one person at one floor.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define DEBUG

using namespace std;

const int n = 10;
bool visit[n];

void dfs(int x, int seat[], vector<int>& rec)
{
    visit[x] = true;
    rec.push_back(x);
    if(!visit[seat[x]])
    {
        dfs(seat[x], seat, rec);
    }
}

int findMinLift(int seat[])
{
    int i = 0;
    int ret = 0;

    vector<int> list;
    memset(visit, false, sizeof(visit));
    while(true)
    {
        list.clear();
        for(i = 0; i < n; i++)
        {
            if(seat[i] != i && !visit[i])
            {
                dfs(i, seat, list);
                #ifdef DEBUG
                for(vector<int>::iterator it = list.begin(); it != list.end(); it++)
                {
                    cout << (*it) << " ";
                }
                cout << endl;
                #endif
                if(list.size() > 1)
                {
                    ret += list.size();
                }
                break;
            }
        }
        if(i == n)
        {
            break;
        }
    }
    return ret;
}

int main()
{
    int seat[n] = {3, 8, 9, 4, 0, 1, 5, 2, 6, 7};

    int min = findMinLift(seat);

    cout << min;

    return 0;
}
