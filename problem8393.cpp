#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int result = 0;
	for(int i=1; i<n+1;i++)
	{
		result += i;
	}
	cout<<result;
}
