#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	/* tmpC and tmpL record the values of C and L */
	int i = 0, j = 0, tmpC = 0, tmpL = 0;
	int T = 0, N = 0, M = 0, ret = 0;
	int intL[101], floL[101];

	cin >> T;

	for(i = 0; i < T; i++)
	{
		cin >> N >> M;

		ret = 0;

		/* initialize the intL and floL to 0 */
		for(j = 0; j < 101; intL[j++] = 0);
		for(j = 0; j < 101; floL[j++] = 0);

		/* record the energy and level of Soints */
		for(j = 0; j < N; j++)
		{
			cin >> tmpC >> tmpL;
			intL[tmpL] += tmpC;
		}

		/* record the energy and level of Sofloats */
		for(j = 0; j < M; j++)
		{
			cin >> tmpC >> tmpL;
			floL[tmpL] += tmpC;
		}

		for(j = 1; j < 101; j++)
		{
			if(intL[j] < floL[j])
			{
				ret += floL[j] - intL[j];
			}
		}
		cout << ret << endl;
	}
	return 0;
}