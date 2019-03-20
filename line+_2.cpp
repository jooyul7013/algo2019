#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;
vector<string> v2;
vector<char> v3;

int main(void)
{
	int tmp = 0;
	int upperCnt = 0;
	int digitCnt = 0;
	string tmpString = "";
	string s;
	cin>>s;
	for(int i=0; i<s.length(); i++)
	{
		if(isupper(s[i]))
		{
			upperCnt++;
			if(i == 0)
			{
				tmpString += s[i];
			}
			else
			{
				v2.push_back(tmpString);
				tmpString = "";
				tmpString += s[i];
			}
		}
		if(islower(s[i]))
		{
			tmpString += s[i];
		}
		if(isdigit(s[i]))
		{
			digitCnt++;
			v3.push_back(s[i]);
		}
	}
	v2.push_back(tmpString);//마지막 원소기호 넣어줌 
	
	if(digitCnt==upperCnt)//원소기호와 원소 개수가 짝이 맞을때만 출력 
	{
		for(int i=0;i<digitCnt;i++)
		{
			if(i == digitCnt-1)
			{
				if(v3[i] == '1')
					cout<<v2[i]<<endl;
				else
					cout<<v2[i]<<v3[i]<<endl;
			}	
			else
			{
				if(v3[i] == '1')
					cout<<v2[i];
				else
					cout<<v2[i]<<v3[i];
			}
		}
	}
	else
	{
		cout<<"error"<<endl;
	}
}
