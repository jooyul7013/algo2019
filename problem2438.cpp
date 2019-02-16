#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin>>N;
	
	for(int i=1; i<N+1; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(j==i-1)
				cout<<"*"<<"\n";
			else
				cout<<"*";
		}
	}
}
