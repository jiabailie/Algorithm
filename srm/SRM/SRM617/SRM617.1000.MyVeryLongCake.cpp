#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class MyVeryLongCake
{
private:
    vector<int> pfactor;
    void generate(int n);
public:
    int cut(int n);
};

void MyVeryLongCake::generate(int n)
{
    pfactor.clear();
    int t = n;
    for(int i = 2; i * i <= t; ++i)
    {
        if(t % i == 0)
        {
            pfactor.push_back(i);
            while(t % i == 0)
            {
                t /= i;
            }
        }
    }
    if(t > 1)
    {
        pfactor.push_back(t);
    }
}

int MyVeryLongCake::cut(int n)
{
    generate(n);
    int t = n;
    for(vector<int>::iterator it = pfactor.begin(); it != pfactor.end(); ++it)
    {
        t -= t / (*it);
    }
    return n - t;
}

int main()
{
    MyVeryLongCake mvlc;
    int test[5] = {6, 3, 15, 1000000000, 577007436};
    int expe[5] = {4, 1, 7, 600000000, 384671628};
    for(int i = 0; i < 5; ++i)
    {
        bool x = mvlc.cut(test[i]) == expe[i];
        cout << (x ? "Pass" : "No pass") << endl;
    }
    return 0;
}