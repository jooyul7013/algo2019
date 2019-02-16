#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin>>N;
	
	for(int i=1; i<N+1; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(j<N-i)
				cout<<" ";
			else if(j>=N-i)
			{
				if(j==N-1)
					cout<<"*"<<"\n";
				else
					cout<<"*";
			}
		}
	}
}
