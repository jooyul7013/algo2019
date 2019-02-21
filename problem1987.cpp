#include <iostream>

using namespace std;
int R, C;
int maxCnt = 1;//max는 최대칸수 
char map[20][20];
int visit[20][20] = {0};
int charVisit[1000] = {0};//방문한 알파벳인지 체크 

bool charCheck(char c)
{
	if(charVisit[c]==0)
		return true;
	else
		return false;
}

void DFS(int x, int y, int depth)
{
	if(depth>maxCnt)
		maxCnt = depth;
	
	if(x>0&& visit[x-1][y]==0 && charCheck(map[x-1][y]))//좌 
	{
		visit[x-1][y] = 1;
		charVisit[map[x-1][y]] = 1;
		DFS(x-1,y,depth+1);
		visit[x-1][y] = 0;
		charVisit[map[x-1][y]] = 0;
	}
	if(y>0&& visit[x][y-1]==0 && charCheck(map[x][y-1]))//위 
	{
		visit[x][y-1] = 1;
		charVisit[map[x][y-1]] = 1;
		DFS(x,y-1,depth+1);
		visit[x][y-1] = 0;
		charVisit[map[x][y-1]] = 0;
	}
	if(x<R-1&&visit[x+1][y]==0&& charCheck(map[x+1][y]))//우 
	{
		visit[x+1][y] = 1;
		charVisit[map[x+1][y]] = 1;
		DFS(x+1,y,depth+1); 
		visit[x+1][y] = 0;
		charVisit[map[x+1][y]] = 0;
	}
	if(y<C-1&&visit[x][y+1]==0&& charCheck(map[x][y+1]))//아래 
	{
		visit[x][y+1] = 1;
		charVisit[map[x][y+1]] = 1;
		DFS(x,y+1,depth+1); 
		visit[x][y+1] = 0;
		charVisit[map[x][y+1]] = 0;
	}
	return; 
}

int main(void)
{
	cin>>R>>C;
	
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			cin>>map[i][j]; 
		}
	} 
	charVisit[map[0][0]] = 1;
	visit[0][0] == 1;
	DFS(0, 0,1);
	
	cout<<maxCnt<<endl;	
}
