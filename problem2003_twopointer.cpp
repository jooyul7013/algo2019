#include <iostream>
//�������͸� �̿��� Ǯ�� 
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
		if(sum>=M)//�հ谡 M���� ū ��� �� �������� ���δ�. 
			sum-=arr[low++];
		else if(high==N) 
			break;
		else
			sum+=arr[high++];//�հ谡 M���� ���� ��� ������ �ø���. 
		//�������� ���� ��� N����ŭ �̵��ϹǷ� �ð����⵵�� O(n) 
		if(sum == M)
			count++;
	}
	cout<<count<<'\n';
	return 0;
}
