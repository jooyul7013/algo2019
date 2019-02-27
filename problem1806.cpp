#include <iostream>

using namespace std;

long long N, S;
long long arr[100000];
long long maxGap = 99999;
bool check = 0;
int main(void)
{
	cin>>N>>S;
	long long high = 0;
	long long low = 0;
	long long sum = 0;
	
	
	for(long long i = 0; i<N; i++)
	{
		cin>>arr[i];
	}
	
	while(1)
	{
		if(sum>=S)
			sum-=arr[low++];
		else if(high == N)
			break;
		else
			sum+=arr[high++];
			
		if(sum >= S)
		{
			check = 1;
			
			if(high-low < maxGap)
				maxGap = high-low;
				
		}
	}
	if(check == 0)
		cout<<0<<endl;
	else
		cout<<maxGap<<endl;
	
	return 0;
	
}
