#include <iostream>

using namespace std;

int N;
long long M;
int arr[10000] = {0};//�迭 A 
int visit[2] = {0};
int count = 0;//����� �� ���
int over = 0; 

void check()
{
	int sum = 0;
	for(int i=visit[0]; i<visit[1]+1; i++)
	{
		sum+=arr[i];
	}
	over = sum;
	if(sum == M)//arr[visit[0]]���� arr[visit[1]]������ ���� M�� ������ ����Ǽ� ���� 
		count++;
}

void DFS(int depth)
{
	if(depth == 2)//���� �ΰ��� �� �� ��� 
	{
		check();//check �Լ� ��ȯ
		return; 
	}
	
	for(int i = visit[0]+1; i<N; i++)
	{
		visit[1] = i;
		DFS(depth+1);
		visit[1] = 0;
		if(over >= M)//visit[1]������ ���� �̹� M�� �Ѿ��ٸ� �� ȣ���ϴ°��� ���ǹ� 
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
		//visit[0] = 0;// ���� ���ʿ� ���� �����ε� �ϴ�. 
	}
	cout<<count<<'\n';//�� ����� �� ��� 
	
}
