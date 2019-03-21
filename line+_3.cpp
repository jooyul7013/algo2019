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
vector<char*> t2;
//vector<string> tmp;//임시로 사용할 벡터 

int N;

int main(void)
{
	int cnt = 0;
	int cnt2 = 0;
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
	
	scanf("%d",&N);
	getchar();
	
	for(int i=0; i<N; i++)
	{
		char *str = new char[99999];
		scanf("%[^\n]", str);
		getchar();
		cout<<str<<endl;
		t2.push_back(str);
		
	}
	
	for(int i=0; i<strlen(t2[0]); i++)
	{
		if(isspace(t2[0][i]))
			cnt2++;
	}
	
	
	return 0;
}
