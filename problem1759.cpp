#include <iostream>
#include <set>

using namespace std;
set<string> result;
int visit[15] = {0};
int L, C;
string s = "";

int countVowel(string str)//���� �˻� �Ͽ� ���� ���� 
{
	int cnt = 0;
	for(int i = 0; i<str.length(); i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			cnt++;
		
	}
	
	return cnt;
}
int countConstant(string str)// ���� �˻��Ͽ� ���� ���� 
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
		if(countVowel(str)>=1&&countConstant(str)>=2)//�� �ϼ����� �� �ڸ��� ���� �˻� 
			result.insert(str);//set �����̳ʿ� ���� �� �ڵ����� ���ĵȴ� 
		return;
	}
	
	for(int i = 0; i<C; i++)
	{
		if(visit[i]==0 && s[i] > str[str.length()-1])//�湮�� ���� ���� �� �������� ���� Ŭ �� 
		{
			visit[i] = 1;
			tmp.push_back(s[i]);
			DFS(tmp, visit);//��͸� �̿��� DFS 
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
		s.push_back(c);//ó���� ���ڿ� �Է¹޴� �κ� 
	}
	for(int i=0; i<C; i++)
	{
		string tmp = "";
		tmp.push_back(s[i]);//�ѱ��� ¥�� ��Ʈ���� �����Ͽ� DFS���ڷ� ���� 
		visit[i] = 1;
		DFS(tmp, visit);//visit�迭 ���� �Ź� �ʱ�ȭ�Ͽ� �����Ѵ� 
		for(int j=0; j<15; j++)
		{
			visit[j] = 0;
		}
	}
	set<string>::iterator iter  = result.begin();//set �����̳� ����ϴ� ���(iterator) 
	for(int i = 0; i<result.size(); i++)
	{
		cout<<*iter<<endl;
		iter++;
	}
	
	return 0;
	
}
