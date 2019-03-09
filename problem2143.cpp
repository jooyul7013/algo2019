#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long T;
int N;
int M;
long long arr1[1000];
long long arr2[1000];
long long total_count = 0;
vector<long long> v1;
vector<long long> v2;


int main(void)
{
	int i;
	cin>>T;
	cin>>N;
	for(i=0; i<N; i++)
	{
		cin>>arr1[i];
	}
	cin>>M;
	for(i=0; i<M; i++)
	{
		cin>>arr2[i];
	}
	
	for(i=0; i<N; i++)
	{
		int sum = arr1[i];
		v1.push_back(sum);
		for(int j=i+1; j<N; j++)
		{
			sum+=arr1[j];
			v1.push_back(sum);
		}
	}
	for(i=0; i<M; i++)
	{
		int sum = arr2[i];
		v2.push_back(sum);
		for(int j=i+1; j<M; j++)
		{
			sum+=arr2[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(),v1.end());
	for(i=0; i<v2.size(); i++)
	{
		long long target = T-v2[i];
		auto high = upper_bound(v1.begin(), v1.end(),target);
		auto low = lower_bound(v1.begin(), v1.end(),target);
		total_count += (high-low);
	}
	cout<<total_count<<endl;
}
