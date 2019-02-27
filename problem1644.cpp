#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool visit[4000001] = {0};//소수 판별할 때 쓰일 배열 
long long N = 0;
vector<long long> v;//소수를 넣을 vector
int count = 0;//총 경우의 수 출력할 변수 
 
int main(void)
{
	cin>>N;
	visit[0] = 1;
	visit[1] = 1;//1과 0은 소수에서 제외
	long long low = 0;
	long long high = 0;
	long long sum = 0;
	  
	for(long long i=2; i<sqrt(N)+1; i++)
	{
		if(visit[i] == 1)
		{
			continue;
		}
		for(int j=i+i; j<N+1; j+=i)//배수가 되는 수를 모두 체크해주는 부분(에라토스테네스의 체) 
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
