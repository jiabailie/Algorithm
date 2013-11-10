/* To array[0, 1, ..., n]
 * result[i] = array[0] * array[1] * ... * array[i - 1] * array[i + 1] * ... * array[n - 1]
 */
 
#include <cstdio>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

inline vector<ll> calc1(int n, vector<ll> input)
{
    ll multi = 0; // input[0] * ... * input[n - 1]
    int c0 = 0;   // the amount of 0
    vector<ll> result;
    
    multi = 1;
    for(vector<ll>::iterator it = input.begin(); it != input.end(); it++)
    {
        if(*it) // input[i] != 0
        {
            multi *= (*it);
        }
        else
        {
            c0 = c0 + 1;
        }
        result.push_back(0);
    }
    
    if(c0 >= 2) 
    { 
        return result;
    }
    result.clear();  
    for(vector<ll>::iterator it = input.begin(); it != input.end(); it++) // c0 <= 1
    {
        if(*it) // input[i] != 0
        {
            result.push_back(multi / (*it));
        }
        else   // input[i] == 0
        {
            result.push_back(multi);
        } 
    }
    
    return result;
}
     
     
 // result[i] = (input[0] * input[1] * .. * input[i - 1]) * (input[i + 1] * input[i + 2] * ... * input[n - 1])
 // before[i] = before[i - 1] * input[i - 1]    
 // after[i] = after[i + 1] * input[i + 1]   
inline vector<ll> calc2(int n, vector<ll> input)
{
    int i = 0;
    vector<ll> result(n, 0);
    vector<ll> beforeI(n, 1);
    vector<ll> afterI(n, 1);
    
    for(i = 1; i < n; i++)
    {
        beforeI[i] = beforeI[i - 1] * input[i - 1];
    }
    for(i = n - 2; i >= 0; i--)
    {
        afterI[i] = afterI[i + 1] * input[i + 1];
    }
    
    for(i = 0; i < n; i++)
    {
        result[i] = beforeI[i] * afterI[i];
    }
    return result;
}   

int main()
{
	int i = 0;
	vector<ll> input;
	
	for(i = 1; i < 5; i++) { input.push_back(i); }

	vector<ll> ret1 = calc1(4, input);
	vector<ll> ret2 = calc2(4, input);

	for(i = 0; i < 4; i++)
	{
		cout << ret1[i] << " ";
	}
	cout << endl;

	for(i = 0; i < 4; i++)
	{
		cout << ret2[i] << " ";
	}
	cout << endl;	
	
	return 0;
}
