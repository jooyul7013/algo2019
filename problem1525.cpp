#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;


typedef struct puzzle{
    string str;
    int depth;
}puzzle;

queue<puzzle> q;
set<string> v;
string answer = "123456780";
int result = -1;

bool checkVisit(string s)
{
    if(v.find(s)==v.end())
    {
    	return false;
	}
	else
	{
		return true;
	}
}

void BFS()
{
    puzzle tmp;
    while(!q.empty())
    {
        puzzle p = q.front();
        q.pop();
        char c;
        if(p.str == answer)//������ ã�� ���
        {
				result = p.depth;
            	return;
        }
        
        //���� �ű涧
        for(int i=0; i<9; i++)
        {
            if(p.str[i] == '0')//0�� ã�� ���
            {
                //��
                if(i>2)//���� �ű� �� �ִٸ�
                {
                    tmp = p;
                    c = tmp.str[i];
                    tmp.str[i] = tmp.str[i-3];
                    tmp.str[i-3] = c;
                    tmp.depth++;
                    if(checkVisit(tmp.str)==false)
                    {
                        q.push(tmp);
                        v.insert(tmp.str);
                    }
                }
                //�Ʒ�
                if(i<6)
                {
                    tmp = p;
                    c = tmp.str[i];
                    tmp.str[i] = tmp.str[i+3];
                    tmp.str[i+3] = c;
                    tmp.depth++;
                    if(checkVisit(tmp.str)==false)
                    {
                        q.push(tmp);
                        v.insert(tmp.str);
                    }
                }
                if(i%3!=0)
                {
                    tmp = p;
                    c = tmp.str[i];
                    tmp.str[i] = tmp.str[i-1];
                    tmp.str[i-1] = c;
                    tmp.depth++;
                    if(checkVisit(tmp.str)==false)
                    {
                        q.push(tmp);
                        v.insert(tmp.str);
                    }
                }
                if(i%3!=2)
                {
                    tmp = p;
                    c = tmp.str[i];
                    tmp.str[i] = tmp.str[i+1];
                    tmp.str[i+1] = c;
                    tmp.depth++;
                    if(checkVisit(tmp.str)==false)
                    {
                        q.push(tmp);
                        v.insert(tmp.str);
                    }
                }    
                break;
            }
        }
        
    }
    
}

int main(void)
{
    puzzle p;
    p.str = "";
    char c;
    for(int i=0; i<9; i++)
    {
        cin>>c;
        p.str.push_back(c);
    }
    p.depth = 0;
    q.push(p);
    BFS();
    cout<<result;
}
