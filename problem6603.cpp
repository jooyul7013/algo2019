#include <iostream>

using namespace std;

int k = 0;
int arr[13] = {0};//k개의 숫자를 저장하는 장소 
int visit[13] = {0};
int lotto[13] = {0}; 

void DFS(int depth)
{
	if(depth == 6)
	{
		for(int i = 0; i<6; i++)
		{
			if(i== 5)
				cout<<lotto[i]<<'\n';
			else
				cout<<lotto[i]<<" ";
		}
		return;
	}
	
	for(int i = 0; i<k; i++)
	{
		if(visit[i]==0 && arr[i]>lotto[depth-1])
		{
			lotto[depth] = arr[i];
			visit[i] = 1;
			DFS(depth+1);
			lotto[depth] = 0;
			visit[i] = 0;
		}
	}
	
	return;
}

int main(void)
{
	while(cin>>k)
	{
		if(k == 0)
		{
			break;
		}
		
		for(int i=0; i<k; i++)
		{
			cin>>arr[i];
		}
		
		for(int i=0; i<k; i++)
		{
			lotto[0] = arr[i];
			visit[i] = 1;
			DFS(1);
			lotto[0] = 0;
			visit[i] = 0;
		}
		
	}
	
}
