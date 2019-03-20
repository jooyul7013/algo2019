#include <iostream>
#include <math.h>

using namespace std;

long long N;9
int main(void)
{
	cin>>N;
	long long tmp;
	for(long long i = sqrt(N)/1; i>0; i--)
	{
		if(N%i == 0)//나누어떨어지는 경우 
		{
			tmp = abs(i-(N/i));
			break;	
		}
	}
	cout<<tmp<<endl;	
	return 0;
}
