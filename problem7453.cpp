#include <iostream>
#include <algorithm>

using namespace std;

int A[4000] = {0};
int B[4000] = {0};
int C[4000] = {0};
int D[4000] = {0};
int AB[16000000] = {0};
int CD[16000000] = {0};
int N;
int tmp = 0;
long long result = 0;

void DFS(int visit[2], int depth)
{
	if(depth == 1)
	{
		AB[tmp] = -(A[visit[0]]+B[visit[1]]);
		CD[tmp] = C[visit[0]]+D[visit[1]];
		tmp++;
		return;	
	}
	else
	{
		for(int i = 0; i<N; i++)
		{
			visit[depth+1] = i;
			DFS(visit, depth+1);
		}
	}
	return;
}

int main(void)
{
	cin>>N;
	int NN = N*N;
	int visit[4] = {0};
	
	for(int i=0; i<N; i++)
	{
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	
	for(int i=0; i<N; i++)
	{
		visit[0] = i;
		DFS(visit, 0);
	}
	sort(AB, AB+NN);//AB¸¦ Á¤·Ä 
	
	for(int i=0; i<NN; i++)
	{
		int left =0;
		int right = NN;
		
		while(left<right)
		{
			int mid = (left+right)/2;
			if(AB[mid]<CD[i])
				left = mid + 1;
			else
				right = mid;
		}
		long long low = left;
		
		left = 0;
		right = NN;
		
		while(left<right)
		{
			int mid = (left+right)/2;
			if(AB[mid]<=CD[i])
				left = mid + 1;
			else
				right = mid;
		}
		long long high = left;
		
		result += high-low;
	}
	
	cout<<result<<endl;
}
