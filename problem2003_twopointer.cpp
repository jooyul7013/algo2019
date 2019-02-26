#include <iostream>
//투포인터를 이용한 풀이 
int N;
long long M;
int arr[10000] = {0};

using namespace std;

int main(void)
{
	int low = 0;
	int high = 0;
	long long sum = 0;
	int count  = 0;
	cin>>N>>M;
	
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
	}
	while(1)
	{
		if(sum>=M)//합계가 M보다 큰 경우 맨 시작점을 줄인다. 
			sum-=arr[low++];
		else if(high==N) 
			break;
		else
			sum+=arr[high++];//합계가 M보다 작은 경우 끝점을 늘린다. 
		//시작점과 끝점 모두 N번만큼 이동하므로 시간복잡도는 O(n) 
		if(sum == M)
			count++;
	}
	cout<<count<<'\n';
	return 0;
}
