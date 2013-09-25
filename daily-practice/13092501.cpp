/* Given an n X n matrix, find all elements which are zero, 
 * when found set all the elements in that row and column to zero. 
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n = 10;

inline void setRow(int row, int** matrix)
{
	for(int i = 0; i < n; i++) { matrix[row][i] = 0; }
}

inline void setColumn(int column, int** matrix)
{
	for(int i = 0; i < n; i++) { matrix[i][column] = 0; }
}

inline void setZero1(int** matrix)
{
	int i = 0, j = 0;
	bool zeroRow = false;
	bool zeroCol = false;

	for(i = 0; i < n; i++)
	{
		if(matrix[0][i] == 0)
		{
			zeroRow = true;
		}
		if(matrix[i][0] == 0)
		{
			zeroCol = true;
		}
	}
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(i = 1; i < n; i++)
	{
		if(matrix[i][0] == 0)
		{
			setRow(i, matrix);
		}
		if(matrix[0][i] == 0)
		{
			setColumn(i, matrix);
		}
	}
	if(zeroRow) { setRow(0, matrix); }
	if(zeroCol) { setColumn(0, matrix); }
}

inline void setZero2(int** matrix)
{
	int i = 0, j = 0;
	bool* row = (bool*)malloc(sizeof(bool) * n);
	bool* col = (bool*)malloc(sizeof(bool) * n);

	memset(row, false, sizeof(bool) * n);
	memset(col, false, sizeof(bool) * n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(matrix[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		if(row[i]) { setRow(i, matrix); }
		if(col[i]) { setColumn(i, matrix); }
	}
}

inline void displayMatrix(int** matrix)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

inline int** copyMatrix(int** matrix)
{
	if(!matrix) 
	{ 
		cout << "The pointer is empty." << endl;
		return 0; 
	}
	int** cmatrix = (int**)malloc(sizeof(int*) * n);
	for(int i = 0; i < n; i++)
	{
		cmatrix[i] = (int*)malloc(sizeof(int) * n);
		memcpy_s(cmatrix[i], sizeof(int) * n, matrix[i], sizeof(int) * n);
	}
	return cmatrix;
}

inline bool judgeMatrixes(int** matrix1, int** matrix2)
{
	bool ret = true;
	for(int i = 0; i < n && ret; i++)
	{
		for(int j = 0; j < n && ret; j++)
		{
			if(matrix1[i][j] != matrix2[i][j]) { ret = false; }
		}
	}
	return ret;
}

inline void deleteMatrix(int** matrix)
{
	if(!matrix) 
	{ 
		cout << "The pointer is empty." << endl;
		return; 
	}

	for(int i = 0; i < n; i++)
	{
		if(matrix[i])
		{
			free(matrix[i]);
		}
	}
	free(matrix);
}

int main()
{
	int i = 0, j = 0;
	n = (rand() % 10) + 10;
	int** matrix = (int**)malloc(sizeof(int*) * n);
	for(i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * n);
		for(j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}

	int** cmatrix = copyMatrix(matrix);

	displayMatrix(matrix);

	cout << endl;
	
	setZero1(matrix);
	setZero2(cmatrix);

	cout << (judgeMatrixes(matrix, cmatrix) ? "Equal" : "Not equal") << endl;

	deleteMatrix(matrix);
	deleteMatrix(cmatrix);

	return 0;
}
