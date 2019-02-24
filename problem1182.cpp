#include <iostream>

using namespace std;

int N, S;
int arr[20] = {0};
int visit[20] = {0};
int subset[29] = {0};
int count = 0;

void DFS(int depth, int digit)
{
	int sum = 0;
	for(int i=0; i<depth; i++)
	{
		sum += subset[i];
		//cout<<subset[i];
	}
	//cout<<endl;
	if(sum == S)
		count++;
	
	for(int i=digit+1; i<N; i++)
	{
		subset[depth] = arr[i];
		DFS(depth+1, i);
		subset[depth] = 0;
	}
	return;
}

int main(void)
{
	cin>>N>>S;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0; i<N; i++)
	{
		subset[0] = arr[i];
		visit[i] = 1;
		DFS(1,i);
		subset[0] = 0;
		visit[i] = 0;
	}
	
	cout<<count<<endl;
	
}
