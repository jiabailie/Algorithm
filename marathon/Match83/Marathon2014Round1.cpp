#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#define DEBUG
#undef  DEBUG
using namespace std;

typedef long long ll;

const ll mul = 48271;
const ll mod = 2147483647;
const int dirX[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dirY[8] = {0, 1, 0, -1, 1, -1, -1, 1};

struct idir
{
    enum direction 
    { 
        up = 0, 
        right = 1, 
        down = 2, 
        left = 3, 
        rt = 4, 
        lt = 5, 
        lb = 6, 
        rb = 7 
    };
};

// rel[0] => Minus = N;
// rel[1] => Minus = 1.
const int rel[2][2][4] = {{{0, 0, 3, 3}, {1, 2, 1, 3}}, {{0, 0, 1, 1}, {2, 3, 2, 3}}};

int N = 0;
int iboard[16][16];

// 0 right-bottom
// 1 right-top
// 2 left-top
// 3 left-bottom
set<int> triples[4];

struct neighbour
{
    int x;
    int y;
    int dist;
    int dir;
    neighbour() {}
    neighbour(int _x, int _y) : x(_x), y(_y), dist(-1), dir(-1) {}
    neighbour(int _x, int _y, int _dist, int _dir) : x(_x), y(_y), dist(_dist), dir(_dir) {}
    neighbour(const neighbour &_m) : x(_m.x), y(_m.y), dist(_m.dist), dir(_m.dir) {}
    neighbour& operator=(const neighbour &_m)
    {
        if(&_m == this) { return *this; }
        this->x = _m.x;
        this->y = _m.y;
        this->dist = _m.dist;
        this->dir = _m.dir;
        return *this;
    }
};

vector<neighbour> cneighbour[7];

inline int imin(int x, int y) { return x < y ? x : y; }
inline int imax(int x, int y) { return x > y ? x : y; }
inline int iabs(int x, int y) { return x > y ? x - y : y - x; }
inline int setPos(int x, int y) { return x * N + y; }
inline void getPos(int p, int &x, int &y) { x = p / N; y = p % N; }

class SquareRemover
{
private:    
    int lt_x;
    int lt_y;
    int rb_x;
    int rb_y;
    int _colors;
    ll _cur_color;

    bool rbTriple(int x, int y)
    {
        int dirs[3] = {idir::up, idir::lt, idir::left};
        return judgeTriple(x, y, dirs);
    }

    bool rtTriple(int x, int y)
    {
        int dirs[3] = {idir::left, idir::lb, idir::down};
        return judgeTriple(x, y, dirs);
    }

    bool ltTriple(int x, int y)
    {
        int dirs[3] = {idir::right, idir::rb, idir::down};
        return judgeTriple(x, y, dirs);
    }

    bool lbTriple(int x, int y)
    {
        int dirs[3] = {idir::up, idir::rt, idir::right};
        return judgeTriple(x, y, dirs);
    }

    void resetStructures(vector<string> board)
    {
        int i = 0, j = 0;
        for(i = 0; i < 7; cneighbour[i].clear(), ++i);
        for(i = 0; i < 4; triples[i].clear(), ++i);
        memset(iboard, 0, sizeof(iboard));
        for(i = 0; i < N; ++i)
        {
            for(j = 0; j < N; ++j)
            {
                iboard[i][j] = board[i][j] - '0';
            }
        }
    }

    int getNextColor()
    {
        int ret = int(_cur_color % _colors);
        _cur_color = (_cur_color * mul) % mod;
        return ret;
    }

    void handleRange(int &sX, int &sY, int &eX, int &eY)
    {
        sX = imax(0, sX);
        sY = imax(0, sY);
        eX = imin(N - 1, eX);
        eY = imin(N - 1, eY);
    }

    bool judgeTriple(int x, int y, int dirs[3])
    {
        int i = 0, j = 0;
        int tx = 0, ty = 0;
        for(i = 0; i < 3; ++i)
        {
            j = dirs[i];
            tx = x + dirX[j];
            ty = y + dirY[j];
            if(!(tx >= 0 && tx < N && ty >= 0 && ty < N))
            { 
                return false;
            }
        }

        if(!(iboard[x + dirX[dirs[0]]][y + dirY[dirs[0]]] == iboard[x + dirX[dirs[1]]][y + dirY[dirs[1]]] &&
             iboard[x + dirX[dirs[0]]][y + dirY[dirs[0]]] == iboard[x + dirX[dirs[2]]][y + dirY[dirs[2]]]))
        {
            return false;
        }
        return true;
    }    

    neighbour findNearestNeighbour(int x, int y)
    {
        bool find = false;
        int i = 0, j = 0;
        int tx = 0, ty = 0;
    
        neighbour ret(x, y);
    
        for(i = 1; i <= N && !find; ++i)
        {
            for(j = 0; j < 4 && !find; ++j)
            {
                tx = x + i * dirX[j];
                ty = y + i * dirY[j];
    
                if(tx >= 0 && tx < N && ty >= 0 && ty < N && iboard[x][y] == iboard[tx][ty])
                {
                    ret.dist = i;
                    ret.dir = j;
                    find = true;
                }
            }
        }
        return ret;
    }

    int getNeighbourColor(int kind, int ind)
    {
        int ret = -1;
        int x = 0, y = 0;
        getPos(ind, x, y);
        if(kind == 0) {    ret = iboard[x - 1][y - 1]; }
        else if(kind == 1) { ret = iboard[x + 1][y - 1]; }
        else if(kind == 2) { ret = iboard[x + 1][y + 1]; }
        else if(kind == 3) { ret = iboard[x - 1][y + 1]; }
        return ret;
    }

    void setDirValue(int kind, int x, int y, int &nx, int &ny)
    {
        switch(kind)
        {
        case idir::up:
            nx = x - 1;
            ny = y;
            break;
        case idir::left:
            nx = x;
            ny = y - 1;
            break;
        case idir::down:
            nx = x + 1;
            ny = y;
            break;
        case idir::right:
            nx = x;
            ny = y + 1;
            break;
        default:
            break;
        }
    }

    void setRetValue(int x, int y, int d, int &pos, int &dir, int &col)
    {
        dir = d;
        pos = setPos(x, y);        
        col = iboard[x][y];
    }

    void formPos(int x, int y, int d, int &ind)
    {
        ind = setPos(x + dirX[d], y + dirY[d]);
    }

    int getNeighboursColor(int kind, int ind, 
        int &nbPos1, int &nbDir1, int &nbCol1, 
        int &nbPos2, int &nbDir2, int &nbCol2)
    {
        int ret = 0;
        int x = 0, y = 0;
        int x1 = 0, y1 = 0, d1 = 0;
        int x2 = 0, y2 = 0, d2 = 0;
        getPos(ind, x, y);

        switch(kind)
        {
        case 0:
            d1 = idir::right;
            d2 = idir::down;
            break;
        case 1:
            d1 = idir::up;
            d2 = idir::right;
            break;
        case 2:
            d1 = idir::up;
            d2 = idir::left;
            break;
        case 3:
            d1 = idir::left;
            d2 = idir::down;
            break;
        default:
            break;
        }
        setDirValue(d1, x, y, x1, y1);
        setDirValue(d2, x, y, x2, y2);
        if(x1 >= 0 && x1 < N && y1 >= 0 && y1 < N)
        {
            ret += 1;
            setRetValue(x1, y1, d1, nbPos1, nbDir1, nbCol1);
        }
        if(x2 >= 0 && x2 < N && y2 >= 0 && y2 < N)
        {
            ret += 1;
            if(ret == 2)
            {            
                setRetValue(x2, y2, d2, nbPos2, nbDir2, nbCol2);
            }
            else if(ret == 1)
            {
                setRetValue(x2, y2, d2, nbPos1, nbDir1, nbCol1);
            }
        }

        return ret;
    }

    void generateNeighbours(int sX, int sY, int eX, int eY)
    {
        handleRange(sX, sY, eX, eY);
        for(int i = sX; i < eX; ++i)
        {
            for(int j = sY; j < eY; ++j)
            {
                cneighbour[iboard[i][j]].push_back(neighbour(findNearestNeighbour(i, j)));
            }
        }
    }

    void getTriples(int sX, int sY, int eX, int eY)
    {
        handleRange(sX, sY, eX, eY);
        for(int i = sX; i < eX; ++i)
        {
            for(int j = sY; j < eY; ++j)
            {
                if(this->rbTriple(i, j)) { triples[0].insert(setPos(i, j)); }
                if(this->rtTriple(i, j)) { triples[1].insert(setPos(i, j)); }
                if(this->ltTriple(i, j)) { triples[2].insert(setPos(i, j)); }
                if(this->lbTriple(i, j)) { triples[3].insert(setPos(i, j)); }
            }
        }
    }

    void globalRemove(int sX, int sY, int eX, int eY)
    {
        handleRange(sX, sY, eX, eY);
        for(int i = sX; i < eX; ++i)
        {
            for(int j = sY; j < eY; ++j)
            {
                if(iboard[i][j] == iboard[i][j + 1] && 
                   iboard[i][j] == iboard[i + 1][j] && 
                   iboard[i][j] == iboard[i + 1][j + 1])
                {
                    iboard[i][j] = getNextColor();
                    iboard[i][j + 1] = getNextColor();
                    iboard[i + 1][j] = getNextColor();
                    iboard[i + 1][j + 1] = getNextColor();
                    j = j + 1;
                }
            }
        }
    }

    void doCompare(int relIndex, int k1, int k2, int i1, int i2, int id, bool &find, int &d, int &kind1, int &kind2, int &ind1, int &ind2)
    {
        for(int i = 0; i < 4 && !find; ++i)
        {
            if(k1 == rel[relIndex][0][i] && k2 == rel[relIndex][1][i])
            {
                find = true;
                kind1 = k1;
                kind2 = k2;
                ind1 = i1;
                ind2 = i2;
                d = id;
            }
        }
    }

    void swapColor(int ind1, int ind2)
    {
        int c = 0;
        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = 0;

        getPos(ind1, x1, x2);
        getPos(ind2, x2, y2);

        c = iboard[x1][y1];
        iboard[x1][y1] = iboard[x2][y2];
        iboard[x2][y2] = c;

        lt_x = imax(0, x1 - 1);
        lt_y = imax(0, y1 - 1);
        rb_x = imin(N - 1, x2 + 1);
        rb_y = imin(N - 1, y2 + 1);
    }

    // d[dir] means ind2 is at which direction of ind1
    bool findMatchTriples(int &d, int &kind1, int &ind1, int &kind2, int &ind2)
    {
        bool find = false;
        int i = 0, j = 0;
        int k = 0, z = 0;
        set<int>::iterator m, n;
        for(i = 0; i < 4 && !find; ++i)
        {
            for(j = 0; j < 4 && !find; ++j)
            {
                if(i == j) { continue; }
                for(m = triples[i].begin(); m != triples[i].end() && !find; ++m)
                {
                    for(n = triples[j].begin(); n != triples[j].end() && !find; ++n)
                    {
                        k = (*m) - (*n);
                        if(k != 1 && k != N) { continue; }
                        if(iboard[(*m) / N][(*m) % N] != getNeighbourColor(j, *n) || 
                           iboard[(*n) / N][(*n) % N] != getNeighbourColor(i, *m))
                        {
                            continue;
                        }                        
                        doCompare((k == N ? 0 : 1), i, j, *m, *n, (k == N ? idir::down : idir::right), find, d, kind1, kind2, ind1, ind2);
                    }
                }
            }
        }
        if(find)
        {
            triples[kind1].erase(ind1);
            triples[kind2].erase(ind2);
        }
        return find;
    }

    bool findRemovableTriple(int &d, int &kind, int &ind)
    {
        bool find = false;
        int ncolor = 0;
        int i = 0, k = 0;
        set<int>::iterator j;
        int nbPos1 = -1, nbDir1 = -1, nbCol1 = -1;
        int nbPos2 = -1, nbDir2 = -1, nbCol2 = -1;

        for(i = 0; i < 4 && !find; ++i)
        {
            for(j = triples[i].begin(); j != triples[i].end() && !find; ++j)
            {
                ncolor = getNeighbourColor(i, *j);
                k = getNeighboursColor(i, *j, nbPos1, nbDir1, nbCol1, nbPos2, nbDir2, nbCol2);
                if(k > 0)
                {
                    if(ncolor == nbCol1)
                    {
                        find = true;
                        d = nbDir1;
                        kind = i;
                        ind = *j;
                    }
                    if(!find && k == 2 && ncolor == nbCol2)
                    {
                        find = true;
                        d = nbDir2;
                        kind = i;
                        ind = *j;
                    }
                }
            }
        }
        if(find)
        {
            triples[kind].erase(ind);
        }
        return find;
    }

    void loopControlTail(int ind1, int ind2)
    {
        swapColor(ind1, ind2);
        globalRemove(lt_x, lt_y, rb_x + 1, rb_y + 1);
        getTriples(imax(0, lt_x - 3), imax(0, lt_y - 3), imin(N, rb_x + 3), imin(N, rb_y + 3));
    }

    void loopControl(int &x, int &y, int &dir)
    {
        int d = 0;
        int ind1 = 0, ind2 = 0;
        int kind1 = 0, kind2 = 0;

        // best, find a pair of matched triples
        bool match = findMatchTriples(d, kind1, ind1, kind2, ind2);
        if(match)
        {
            dir = d;
            getPos(ind1, x, y);
            loopControlTail(ind1, ind2);
            return;
        }

        // if cannot find a pair of matched triples
        // better, find a removable triples
        match = findRemovableTriple(d, kind1, ind1);
        if(match)
        {
            dir = d;
            getPos(ind1, x, y);
            formPos(x, y, d, ind2);
            loopControlTail(ind1, ind2);
            return;
        }
    }
public:
    vector<int> playIt(int colors, vector<string> board, int startSeed);
};

vector<int> SquareRemover::playIt(int colors, vector<string> board, int startSeed)
{
    int i = 0, d = 0;    
    int x = 0, y = 0;
    int loop = 10000;
    vector<int> ret;

    N = board.size();

    _colors = colors;

    _cur_color = startSeed;

    resetStructures(board);

    getTriples(0, 0, N, N);

    //generateNeighbours(0, 0, N, N);

    globalRemove(0, 0, N, N);

    for(i = 0; i < loop; ++i)
    {
        loopControl(x, y, d);
        ret.push_back(x);
        ret.push_back(y);
        ret.push_back(d);
    }

    return ret;
}

int main()
{
    int colors = 0;
    vector<string> board;
    int startSeed = 0;

#ifdef DEBUG
    colors = 5;
    N = 14;
    startSeed = 857377961;
    board.clear();
    for(int i = 0; i < N; ++i)
    {
        string tmp = "";
        for(int j = 0; j < N; ++j)
        {
            tmp.push_back(char('0' + (rand() % 5)));
        }
        board.push_back(tmp);
    }
#else
    cin >> colors >> N;

    for(int i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    cin >> startSeed;
#endif
    SquareRemover sr;
    vector<int> ret = sr.playIt(colors, board, startSeed); 

    for(int i = 0; i < 30000; ++i)
    {
        cout << ret[i] << endl;
    }

    return 0;
}