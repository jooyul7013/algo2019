#include <iostream> 

using namespace std;

int visit[99999] = {0};
int result = 0;
int flag  = 0;
int N;
void DFS(int a)
{
	if(a == N)
	{
		result++;
		return;
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j=0; j<a; j++)
		{
			if(i==visit[j]) 
			{
				flag = 1;
				break;
			}
			if( i+a == j+visit[j] )
			{
				flag = 1;
				break;
			}
			if(a-i==j-visit[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			flag = 0;
			continue;
		}
		else
		{
			visit[a] = i;
			DFS(a+1);
			visit[a] = 0;
		}	
	}
	return;
}

int main(void)
{
	cin>>N;

	for(int i=0; i<N; i++)
	{
		visit[0] = i;
		DFS(1);
		visit[0] = 0;
	}
	cout<<result;
	return 0;
}
