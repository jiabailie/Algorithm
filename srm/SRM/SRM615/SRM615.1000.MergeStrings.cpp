#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string dp[51][51][51];

class MergeStrings 
{ 
public: 
    bool isEqual(string a, string b)
    {
        if(a.size() != b.size())
        {
            return false;
        }
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }

    string smin(string a, string b)
    {
        bool less = false;
        for(int i = 0; i < std::min(a.size(), b.size()); ++i)
        {
            if(a[i] != b[i])
            {
                if(a[i] < b[i])
                {
                    less = true;
                }
                else if(a[i] > b[i])
                {
                    less = false;
                }
                break;
            }
        }
        return less ? a : b;
    }

    string getmin(string S, string A, string B) 
    { 
        int i = 0, j = 0, k = 0;
        string tmp;

        for(i = S.size(); i >= 0; --i)
        {
            for(j = A.size(); j >= 0; --j)
            {
                for(k = B.size(); k >= 0; --k)
                {
                    if(i == S.size())
                    {
                        dp[i][j][k] = "";
                    }
                    else
                    {
                        dp[i][j][k] = "[invalid]";
                        if(j < A.size() && (S[i] == '?' || S[i] == A[j]))
                        {
                            tmp = dp[i + 1][j + 1][k];
                            if(!isEqual(tmp, "[invalid]"))
                            {
                                dp[i][j][k] = smin(dp[i][j][k], string(1, A[j]).append(tmp));
                            }
                        }
                        if(k < B.size() && (S[i] == '?' || S[i] == B[k]))
                        {
                            tmp = dp[i + 1][j][k + 1];
                            if(!isEqual(tmp, "[invalid]"))
                            {
                                dp[i][j][k] = smin(dp[i][j][k], string(1, B[k]).append(tmp));
                            }
                        }
                    }
                }
            }
        }

        return isEqual(dp[0][0][0], "[invalid]") ? string("") : dp[0][0][0];
    }
};

int main()
{
    MergeStrings m;
    string s[5] = {"??CC??", "WHAT?", "PARROT", "???????????", "????K??????????????D???K???K????????K?????K???????"};
    string a[5] = {"ABC", "THE", "PARROT", "AZZAA", "KKKKKDKKKDKKDDKDDDKDKK"};
    string b[5] = {"BCC", "WA", "", "AZAZZA", "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"};
    string ex[5] = {"ABCCBC", "", "PARROT", "AAZAZZAAZZA", "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"};

    for(int i = 0; i < 5; ++i)
    {
        string c = m.getmin(s[i], a[i], b[i]);
        if(m.isEqual(c, ex[i]))
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "NO PASS" << endl;
        }
    }
    return 0;
}