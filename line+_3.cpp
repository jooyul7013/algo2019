#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <ctype.h>

using namespace std;

//table1
vector<char*> t1;
//table2

vector<string> tmp;//임시로 사용할 벡터 

int N;

int main(void)
{
	int cnt = 0;
	scanf("%d",&N);
	getchar();
	
	for(int i=0; i<N; i++)
	{
		char *str = new char[99999];
		scanf("%[^\n]", str);
		getchar();
		cout<<str<<endl;
		t1.push_back(str);
		
	}
	
	for(int i=0; i<strlen(t1[0]); i++)
	{
		if(isspace(t1[0][i]))
			cnt++;
	}
	
	cout<<t1[0][0]<<endl;
	cout<<t1[1]<<endl;
	cout<<t1[2]<<endl;
	
	cout<<N<<endl;
	cout<<cnt<<endl;
	
	return 0;
}
