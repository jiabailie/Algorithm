#include <cstdio>
#include <iostream>

using namespace std;

const int N_MAX = 10;
int matrix[N_MAX][N_MAX];

void iniMatrix()
{
	int start = 1, k = 0;
	for(int i = 1; i < N_MAX; ++i)
	{
		for(int j = 1; j < N_MAX; ++j)
		{
			k = std::max(matrix[i][j - 1], matrix[i - 1][j]);
			matrix[i][j] = k + (rand() % 7);
		}
	}
}

bool stepWise(int target, int &row, int &col)
{
	if(target < matrix[1][1] || target > matrix[N_MAX - 1][N_MAX - 1])
	{
		return false;
	}
	row = 1;
	col = N_MAX - 1;
	while(row <= N_MAX - 1 && col >= 0)
	{
		if(matrix[row][col] < target)
		{
			row += 1;
		}
		else if(matrix[row][col] > target)
		{
			col -= 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void displayMatrix()
{
	for(int i = 1; i < N_MAX; ++i)
	{
		for(int j = 1; j < N_MAX; ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int row = 0;
	int col = 0;
	bool suc = true;
	int target = 27;

	iniMatrix();
	displayMatrix();

	suc = stepWise(target, row, col);

	if(suc)
	{
		cout << row << "\t" << col << endl;
	}

	return 0;
}