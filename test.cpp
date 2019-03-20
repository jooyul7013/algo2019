#include <iostream>

using namespace std;

int test[1000] = {0};

int main(void)
{
	char a = 'A';
	for(int i=0; i<1000; i++)
	{
		test[i] = i;
	}
	cout<<test[a]<<endl;
}
