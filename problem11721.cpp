#include <iostream>

using namespace std;

int main(void)
{
	string str;
	cin>>str;
	
	for(int i = 0; i<str.length(); i++)
	{
		if(i%10 == 9)
			cout<<str[i]<<"\n";
		else
			cout<<str[i];
	}
	
	return 0;
}
