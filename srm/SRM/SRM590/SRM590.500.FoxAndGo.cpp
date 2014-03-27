#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

const int M = 20;

int h = 0;
int w = 0;
int calBlank0 = 0;
int cc[M][M];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

map<int, int> calBlank1;
vector<string> Board;

class FoxAndGo {
public:
  int maxKill(vector <string>);
};

void bfs(int cIndex, int hPos, int wPos)
{
    int i = 0, top = 0;
    int ht = 0, wt = 0;
    set<int> cnt;
    set<int> blank;    
    queue<int> iqueue;

    iqueue.push(hPos * 100 + wPos);
    while(!iqueue.empty())
    {
        top = iqueue.front();
        iqueue.pop();
        cnt.insert(top);
        cc[top / 100][top % 100] = cIndex;

        for(i = 0; i < 4; ++i)
        {
            ht = (top / 100) + dx[i];
            wt = (top % 100) + dy[i];

            if(ht >= 0 && ht < h && wt >= 0 && wt < w)
            {
                if(Board[ht][wt] == 'o' && cc[ht][wt] == 0)
                {
                    iqueue.push(ht * 100 + wt);
                }
                else if(Board[ht][wt] == '.')
                {
                    blank.insert(ht * 100 + wt);
                }
            }
        }
    }

    if(blank.size() == 1)
    {
        if(calBlank1.find(*(blank.begin())) != calBlank1.end())
        {
            calBlank1[*(blank.begin())] += cnt.size();
        }
        else
        {
            calBlank1[*(blank.begin())] = cnt.size();
        }
    }
    else if(blank.size() == 0)
    {
        calBlank0 += cnt.size();
    }
}

int FoxAndGo::maxKill(vector<string> board)
{
    int cnt = 1;

    Board = vector<string>(board.begin(), board.end());
    h = board.size();
    w = board[0].size();
    memset(cc, 0, sizeof(cc));

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(board[i][j] == 'o' && cc[i][j] == 0)
            {
                bfs(cnt, i, j);
                cnt += 1;
            }
        }
    }

    cnt = 0;
    for(map<int, int>::iterator it = calBlank1.begin(); it != calBlank1.end(); ++it)
    {
        if(it->second > cnt)
        {
            cnt = it->second;
        }
    }

    return cnt + calBlank0;
}

int main()
{    
    return 0;
}