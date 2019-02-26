#include <iostream>

using namespace std;

int N;
long long M;
int arr[10000] = {0};//배열 A 
int visit[2] = {0};
int count = 0;//경우의 수 출력
int over = 0; 

void check()
{
	int sum = 0;
	for(int i=visit[0]; i<visit[1]+1; i++)
	{
		sum+=arr[i];
	}
	over = sum;
	if(sum == M)//arr[visit[0]]부터 arr[visit[1]]까지의 합이 M과 같으면 경우의수 증가 
		count++;
}

void DFS(int depth)
{
	if(depth == 2)//숫자 두개를 다 고른 경우 
	{
		check();//check 함수 소환
		return; 
	}
	
	for(int i = visit[0]+1; i<N; i++)
	{
		visit[1] = i;
		DFS(depth+1);
		visit[1] = 0;
		if(over >= M)//visit[1]까지의 합이 이미 M을 넘었다면 더 호출하는것이 무의미 
			return;
	}
	
	return;
}

int main(void)
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
		if(arr[i] == M)
			count++;
	}
	for(int i=0; i<N-1; i++)
	{
		visit[0] = i;
		DFS(1);
		//visit[0] = 0;// 굳이 할필요 없는 라인인듯 하다. 
	}
	cout<<count<<'\n';//총 경우의 수 출력 
	
}
