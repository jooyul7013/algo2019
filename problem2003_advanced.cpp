#include <iostream>

using namespace std;

int N;
long long M;
int arr[10000] = {0};//�迭 A 
int count = 0;//����� �� ���

int main(void)
{
	long long sum = 0;
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
		if(arr[i] == M)
			count++;
	}
	for(int i=0; i<N-1; i++)
	{
		sum = arr[i];
		for(int j= i+1; j<N; j++)
		{
			sum+=arr[j];
			if(sum == M)
				count++;
		} 
	}
	cout<<count<<'\n';//�� ����� �� ��� 
}
