#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class ColorfulCoinsEasy
{
public:
    string isPossible(vector <int> values);
};

string ColorfulCoinsEasy::isPossible(vector<int> values)
{
    vector<int> div;
    sort(values.begin(), values.end());
    for(int i = 1; i < values.size(); ++i)
    {
        div.push_back(values[i] / values[i - 1]);
    }
    sort(div.begin(), div.end());
    for(int i = 0; i < div.size(); ++i)
    {
        if(i + 1 >= div[i])
        {
            return "Impossible";
        }
    }
    return "Possible";
}

int main()
{
    ColorfulCoinsEasy cce;
    vector<int> t;
    int n = 0, k = 0;
    for(int i = 0; i < 8; ++i)
    {
        t.clear();
        cin >> n;
        for(int j = 0; j < n; ++j)
        {
            cin >> k;
            t.push_back(k);
        }
        cout << cce.isPossible(t).c_str() << endl;
    }
    return 0;
}