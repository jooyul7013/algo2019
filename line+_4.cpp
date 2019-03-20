#include <iostream>
#include <vector>
#include <math.h> 

using namespace std;

int N;
vector<int> v;
int len = 0;
int main(void)
{
	cin>>N;
	int tmp;
	for(int i=0; i<N; i++)
	{
		cin>>tmp;
		v.push_back(tmp);
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(v[j]<v[i])//j��° �ǹ��� i��° �ǹ����� ������ 
				continue;
			else if(v[j]>=v[i])//���ų� ũ�ٸ� �װ��� ���� �ִ� ���� 
			{
				tmp = j-i;
				if(tmp>len)
					len = tmp;
				i = j-1;
				break;
			}	
		}
	}
	
	for(int i = N-1; i>=0; i--)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(v[j]<v[i])//j��° �ǹ��� i��° �ǹ����� ������ 
				continue;
			else if(v[j]>=v[i])//���ų� ũ�ٸ� �װ��� ���� �ִ� ���� 
			{
				tmp = i-j;
				if(tmp>len)
					len = tmp;
				i = j+1;
				break;
			}
		}
	}
	
	cout<<len<<endl;
} 
