#include <iostream>

using namespace std;

int n, m;
int result = 0;
int visit[10] = {0};

void DFS(int depth)
{
	if(depth == n)
	{
		result++;
		return;	
	}		
	
	if(depth == 0)
	{
		for(int i=1; i<=m; i++)
		{
			visit[0] = i;
			DFS(1);
			visit[0] = 0;
		}
	}
	else
	{
		if(visit[depth-1]*2>m)
			return;
		else
		{
			for(int i = visit[depth-1]*2; i<=m; i++)
			{
				visit[depth] = i;
				DFS(depth+1);
				visit[depth] = 0;
			}
		}
	}
	
	return;
}


int main(void)
{
	cin>>n>>m;
	DFS(0);
	cout<<result<<endl;
}
