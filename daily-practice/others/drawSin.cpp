#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Divide one cycle into small fractions in the horizontal direction.
const int fraction = 1080;

// Divide one horizontal position into small fractions in the vertical direction.
const int grading = 300;

const double pi = 3.141592653589793;

int main()
{
	int i = 0, j = 0;
	double dots[fraction];
	bool position[fraction][grading];
	
	double each = 2 * pi / fraction;
	double veach = 2.0 / grading;

	memset(dots, 0, sizeof(dots));
	memset(position, 0, sizeof(position));

	for(i = 0; i < fraction; ++i)
	{
		dots[i] = sin(i * each);
		j = (dots[i] + 1) / veach;
		position[i][j] = true;
	}
	
	ofstream fout("../txt/sin.txt");
	if(!fout)
	{
		exit(1);
	}
	for(j = 0; j < grading; ++j)
	{
		for(i = 0; i < fraction; ++i)
		{
			fout << (position[i][j] ? '.' : ' ');
		}
		fout << endl;
	}

	fout.close();

	return 1;
}