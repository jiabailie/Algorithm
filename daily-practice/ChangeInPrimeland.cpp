/* This title comes from codechef ByteCode 2013.
URL: http://www.codechef.com/BTCD2013/problems/CNG
In the country of Numberia, there is a city called Primeland. Sherry is one of the rich inhabitants of the city, who likes to collect coins of various
denominations. Coins in primeland are little strange , they are only available in prime denominations (i.e as coins of value 2,3,5 etc.).
Sherry is taking a tour of the country but as he visits people ask him for change, unfortunately Sherry took coins of only two kinds of
denominations(the coins are of Primeland), he has already made a lot of such changes but then he wonders what is the maximum amount which he can't give
change for using the coins he has.Remember he has coins of only two different denominations and has infinite number of them..

Input
First line of input will contain number of testcases,T.Following T lines will contain two integers c and d separated by a space denoting the denominations
which sherry has while he is on the tour, both c and d are guaranteed to be prime.

Output
For each of the T testcases output one number per line the maximum amount which sherry can't afford to give change for.

Constraints
1 <= T <= 100
2 <= c,d <= 10^6

Example
Input:
2
3 5
2 3
Output:
7
1
 */
 #include <cstdio>
 using namespace std;

 int main()
 {
     int T = 0;
     long long c = 0, d = 0;
     scanf("%d", &T);
     for(int i = 0; i < T; i++)
     {
         scanf("%lld %lld", &c, &d);
         printf("%lld\n", c * d - c - d);
     }
     return 0;
 }
