#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int A, B;
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		cin>>A>>B;
		cout<<A+B<<"\n";
	}
	return 0;
}
