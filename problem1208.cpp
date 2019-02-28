#include <iostream>
#include <vector>

using namespace std;
int N, S;
int arr[40] = {0};
int visit[4000001] = {0};
vector<int> R;

long long count = 0;

void DFS(int before, int sum)
{
	if(sum == S)
		count++;
	
	if(before<N/2)//앞의 절반 
	{
		visit[2000000+sum]++;
		for(int i=before+1; i<N/2; i++)
		{	
			DFS(i, sum+arr[i]);
		}
	}
	else if(before>=N/2)//뒤의 절반 
	{
		R.push_back(sum);
		for(int i=before+1; i<N; i++)
		{	
			DFS(i, sum+arr[i]);
		}
	}
	
	return;
}


int main(void){
	cin>>N>>S;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
	}
	for(int i=0; i<N; i++)
	{
		DFS(i, arr[i]);
	}
	for(int i=0; i<R.size(); i++)
	{
		if(S-R[i]>-2000001&&S-R[i]<2000001)
			count+=visit[2000000+S-R[i]];
	}
	
	cout<<count<<endl;
}
