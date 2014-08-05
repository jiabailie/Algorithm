#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int rowNum = 9;
const int colNum = 9;
int iBoard[rowNum][colNum];
bool bBoard[rowNum][colNum];
void rotateSetValues()
{
	int num = 1;
	int i = 0, j = 0;
	int ltX = 0, ltY = 0;
	int rbX = rowNum - 1, rbY = colNum - 1;
	for( ; ltX <= rbX && ltY <= rbY; ++ltX, ++ltY, --rbX, --rbY)
	{
		// (ltX, ltY) -> (ltX, rbY)
		if(ltY <= rbY)
		{
			for(j = ltY; j <= rbY; ++j)
			{
				if(!iBoard[ltX][j])
				{
					iBoard[ltX][j] = num;
					bBoard[ltX][j] = true;
					num += 1;
				}
			}
		}

		// (ltX + 1, rbY) -> (rbX, rbY)
		if(ltX + 1 <= rbX)
		{
			for(j = ltX + 1; j <= rbX; ++j)
			{
				if(!iBoard[j][rbY])
				{
					iBoard[j][rbY] = num;
					bBoard[j][rbY] = true;
					num += 1;
				}
			}
		}

		// (rbX, rbY - 1) -> (rbX, ltY)
		if(rbY - 1 >= ltY)
		{
			for(j = rbY - 1; j >= ltY; --j)
			{
				if(!bBoard[rbX][j])
				{
					iBoard[rbX][j] = num;
					bBoard[rbX][j] = true;
					num += 1;
				}
			}
		}

		// (rbX - 1, ltY) -> (ltX + 1, ltY)
		if(rbX - 1 >= ltX + 1)
		{
			for(j = rbX - 1; j >= ltX + 1; --j)
			{
				if(!bBoard[j][ltY])
				{
					iBoard[j][ltY] = num;
					bBoard[j][ltY] = true;
					num += 1;
				}
			}
		}
	}
}
void displayBoard(int board[rowNum][colNum])
{
	int i = 0, j = 0;
	for(i = 0; i < rowNum; ++i)
	{
		for(j = 0; j < colNum; ++j)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	memset(iBoard, 0, sizeof(iBoard));
	memset(bBoard, 0, sizeof(bBoard));
	rotateSetValues();
	displayBoard(iBoard);
	return 0;
}