#include <cstdio>
#include <iostream>

using namespace std;

const int N = 10;
const int M = 10;
int matrix[N][M];

void generateMatrix(int n, int m, int matrix[N][M])
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			matrix[i][j] = i * N + j;
		}
	}
}

void printMatrix(int n, int m, int matrix[N][M])
{
	if(n <= 0 || m <= 0 || n > N || m > M)
	{
		return;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

// clockwise
void printMatrixSpiralOrder(int n, int m, int matrix[N][M])
{
	if(n <= 0 || m <= 0 || n > N || m > M)
	{
		return;
	}

	int i = 0;
	int top_X = 0, bottom_X = n - 1;
	int left_Y = 0, right_Y = m - 1;

	while(top_X <= bottom_X && left_Y <= right_Y)
	{
		// a point
		if(top_X == bottom_X && left_Y == right_Y)
		{
			cout << matrix[top_X][left_Y] << " ";
		}
		// a horizontal line
		else if(top_X == bottom_X && left_Y < right_Y)
		{
			for(i = left_Y; i <= right_Y; ++i)
			{
				cout << matrix[top_X][i] << " ";
			}
		}
		// a vertical line
		else if(top_X < bottom_X && left_Y == right_Y)
		{
			for(i = top_X; i <= bottom_X; ++i)
			{
				cout << matrix[i][left_Y] << " ";
			}
		}
		else
		{
			// top left -> top right
			for(i = left_Y; i < right_Y; ++i)
			{
				cout << matrix[top_X][i] << " ";
			}
			// top right -> bottom right
			for(i = top_X; i < bottom_X; ++i)
			{
				cout << matrix[i][right_Y] << " ";
			}
			// bottom right -> bottom left
			for(i = right_Y; i > left_Y; --i)
			{
				cout << matrix[bottom_X][i] << " ";
			}
			// bottom left -> top left
			for(i = bottom_X; i > top_X; --i)
			{
				cout << matrix[i][left_Y] << " ";
			}
		}
		top_X = top_X + 1;		
		bottom_X = bottom_X - 1;
		left_Y = left_Y + 1;
		right_Y = right_Y - 1;
	}
	cout << endl;
}

int main()
{
	generateMatrix(N, M, matrix);

	int n = 4;
	int m = 5;

	printMatrix(n, m, matrix);

	cout << endl;

	printMatrixSpiralOrder(n, m, matrix);

	return 0;
}