#include <iostream>
#include <cstdio>

using namespace std;

int map[9][9] = {0};
int result = 0;

bool areaCheck(int x, int y, int v)
{
	int x_start = x/3;
	int y_start = y/3;
	
	for(int i=x_start*3; i<x_start*3 + 3; i++)
	{
		for(int j=y_start*3; j<y_start*3 + 3; j++)
		{
			if(v==map[i][j])
				return false;
		}
	}
	
	return true;
}
bool crossCheck(int x, int y, int v)
{
	for(int i=0; i<9; i++)
	{
		if(map[x][i]==v)
			return false;
			
		if(map[i][y]==v)
			return false;
	}
	return true;
}

void printMap()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(j == 8)
				cout<<map[i][j]<<endl;
			else
				cout<<map[i][j];
		}
	}
	//result = 1;
}

void resultCheck()
{
	int cnt = 0;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(map[i][j]==0)
				return;
		}
	}
	result = 1;
	printMap();
	return;
}

void DFS()
{
	resultCheck();
	if(result == 1)
	{
		return;
	}
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(map[i][j] == 0)
			{
				for(int k=1; k<10; k++)
				{
					if(areaCheck(i,j,k)==true&&crossCheck(i,j,k)==true)
					{
						map[i][j] = k;
						DFS();
						map[i][j] = 0;
					}
				}
				return;
			}
		}
	}
};

int main(void)
{
	for(int i = 0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	DFS();
}
