#include <iostream>
#include <set>

using namespace std;
set<string> result;
int visit[15] = {0};
int L, C;
string s = "";

int countVowel(string str)//모음 검사 하여 개수 리턴 
{
	int cnt = 0;
	for(int i = 0; i<str.length(); i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			cnt++;
		
	}
	
	return cnt;
}
int countConstant(string str)// 자음 검사하여 개수 리턴 
{
	int cnt = 0;
	for(int i = 0; i<str.length(); i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			continue;
		else
			cnt++;
	}
	return cnt;
}

void DFS(string str, int visit[15])
{
	string tmp = str;
	if(str.length() == L)
	{
		if(countVowel(str)>=1&&countConstant(str)>=2)//다 완성됐을 때 자모음 개수 검사 
			result.insert(str);//set 컨테이너에 넣을 때 자동으로 정렬된다 
		return;
	}
	
	for(int i = 0; i<C; i++)
	{
		if(visit[i]==0 && s[i] > str[str.length()-1])//방문한 적이 없고 맨 마지막거 보다 클 때 
		{
			visit[i] = 1;
			tmp.push_back(s[i]);
			DFS(tmp, visit);//재귀를 이용한 DFS 
			tmp = str;
			visit[i] = 0;
		}
	}
		
} 
int main(void)
{
	cin>>L>>C;
	char c;
	for(int i=0; i<C; i++)
	{
		cin>>c;
		s.push_back(c);//처음에 문자열 입력받는 부분 
	}
	for(int i=0; i<C; i++)
	{
		string tmp = "";
		tmp.push_back(s[i]);//한글자 짜리 스트링을 생성하여 DFS인자로 전달 
		visit[i] = 1;
		DFS(tmp, visit);//visit배열 또한 매번 초기화하여 전달한다 
		for(int j=0; j<15; j++)
		{
			visit[j] = 0;
		}
	}
	set<string>::iterator iter  = result.begin();//set 컨테이너 출력하는 방법(iterator) 
	for(int i = 0; i<result.size(); i++)
	{
		cout<<*iter<<endl;
		iter++;
	}
	
	return 0;
	
}
