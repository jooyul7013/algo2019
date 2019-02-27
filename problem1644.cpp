#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool visit[4000001] = {0};//�Ҽ� �Ǻ��� �� ���� �迭 
long long N = 0;
vector<long long> v;//�Ҽ��� ���� vector
int count = 0;//�� ����� �� ����� ���� 
 
int main(void)
{
	cin>>N;
	visit[0] = 1;
	visit[1] = 1;//1�� 0�� �Ҽ����� ����
	long long low = 0;
	long long high = 0;
	long long sum = 0;
	  
	for(long long i=2; i<sqrt(N)+1; i++)
	{
		if(visit[i] == 1)
		{
			continue;
		}
		for(int j=i+i; j<N+1; j+=i)//����� �Ǵ� ���� ��� üũ���ִ� �κ�(�����佺�׳׽��� ü) 
		{
			visit[j] = 1;
		} 
	}
	
	for(long long i=2; i<N+1; i++)
	{
		if(visit[i] == 0)
			v.push_back(i);
	}
	
	while(1)
	{
		if(sum>=N)
			sum-=v[low++];
		else if(high == v.size())
			break;
		else
			sum+=v[high++];
			
		if(sum == N)
			count++; 
	}
	cout<<count<<endl;
	
	return 0;
}
