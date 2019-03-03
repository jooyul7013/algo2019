#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int S;
int N, M;
int A[1000] = {0};
int B[1000] = {0};
int visit[2] = {0};
int result = 0;
vector<int> A_vector;
vector<int> B_vector;


void DFSA(int depth)
{
	if(depth == 1)//¼ýÀÚ µÎ°³ °ñ¶úÀ» ¶§ 
	{
		int sumA = 0;
		if(visit[1] >= visit[0])
		{
			for(int i=visit[0]; i<visit[1]+1; i++)
			{
				sumA+=A[i];
			}
		}
		else if(visit[1]<visit[0])
		{
			if(visit[0]-visit[1] == 1)
				return;
			for(int i=visit[0]; i<M; i++)
			{
				sumA+=A[i];
			}
			for(int i=0; i<visit[1]+1; i++)
			{
				sumA+=A[i];
			}
		}
		
		A_vector.push_back(sumA);
		if(sumA == S)
			result++;
		return;
	}	
	else
	{
		for(int i=0; i<M; i++)
		{
			visit[1] = i;
			DFSA(depth+1);
		}
	}
}

void DFSB(int depth)
{
	if(depth == 1)//¼ýÀÚ µÎ°³ °ñ¶úÀ» ¶§ 
	{
		int sumB = 0;
		if(visit[1] >= visit[0])
		{
			for(int i=visit[0]; i<visit[1]+1; i++)
			{
				sumB+=B[i];
			}
		}
		else if(visit[1]<visit[0])
		{
			if(visit[0]-visit[1] == 1)
				return;
			for(int i=visit[0]; i<N; i++)
			{
				sumB+=B[i];
			}
			for(int i=0; i<visit[1]+1; i++)
			{
				sumB+=B[i];
			}
		}
		
		B_vector.push_back(sumB);
		if(sumB == S)
			result++;
		return;
	}	
	else
	{
		for(int i=0; i<N; i++)
		{
			visit[1] = i;
			DFSB(depth+1);
		}
	}
}

int main(void)
{
	cin>>S>>M>>N;
	for(int i=0; i<M; i++)
	{
		cin>>A[i];
	}
	for(int i=0; i<N; i++)
	{
		cin>>B[i];
	}
	for(int i=0; i<M; i++)
	{
		visit[0] = i;
		DFSA(0);
	}
	for(int i=0; i<N; i++)
	{
		visit[0] = i;
		DFSB(0);
	}
	
	sort(A_vector.begin(), A_vector.end());// Aº¤ÅÍ Á¤·Ä
	
	for(int i=0; i<B_vector.size(); i++)
	{
		int left = 0;
		int right = A_vector.size();
		while(left<right)
		{
			int mid = (left+right)/2;
			if(A_vector[mid]<S-B_vector[i])
				left = mid+1;
			else
				right = mid;
		}
		long long low = left;
		left = 0;
		right = A_vector.size();
		while(left<right)
		{
			int mid = (left+right)/2;
			if(A_vector[mid]<=S-B_vector[i])
				left = mid+1;
			else
				right = mid;
		}
		long long high = left;
		result+= high-low;
	} 
	cout<<result<<endl;
}
