#include <iostream>

using namespace std;

int N;
bool oddCheck = 0;

bool isOdd(int N)
{
	if(N%2 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	if(isOdd(N)==true)
	{
		oddCheck = 1;
	}
	if(oddCheck == 0)//Â¦¼öÀÏ ¶§
	{
		if(N%6 != 2)
		{
			for(int i=1; i<=N/2; i++)
			{
				cout<<2*i<<'\n';
			}
			for(int i=1; i<=N/2; i++)
			{
				cout<<2*i-1<<'\n';
			}
		}
		else if(N%6 != 0)
		{
			for(int i=1; i<=N/2; i++)
			{
				cout<<1+(2*i+N/2-3)%N<<'\n';
			}
			for(int i=N/2; i>0; i--)
			{
				cout<<N-((2*i+N/2-3)%N)<<'\n';
			}
		}
	}
	else
	{
		N--;
		if(N%6 != 2)
		{
			for(int i=1; i<=N/2; i++)
			{
				cout<<2*i<<'\n';
			}
			for(int i=1; i<=N/2; i++)
			{
				cout<<2*i-1<<'\n';
			}
		}
		else if(N%6 != 0)
		{
			for(int i=1; i<=N/2; i++)
			{
				cout<<1+(2*i+N/2-3)%N<<'\n';
			}
			for(int i=N/2; i>0; i--)
			{
				cout<<N-((2*i+N/2-3)%N)<<'\n';
			}
		}
		cout<<N+1<<endl;
	}
	return 0;
}
