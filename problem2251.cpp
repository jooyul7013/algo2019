#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct triple{
	int first;
	int second;
	int third;
}triple;

queue<triple> q;
vector<int> v;
int A, B, C;
int visit[201][201][201] = {0};

void AddToVector(int C)
{
	int flag = 0;
	for(int i = 0; i<v.size(); i++)
	{
		if(v[i] == C)
			flag = 1;
	}
	if(flag == 1)
	{
		return;
	}
	else if(flag == 0)
	{
		v.push_back(C);
	}
}

void BFS()
{
	triple tmp;
	while(!q.empty())
	{
		triple t = q.front();
		q.pop();
		//cout<<"A = "<<t.first<<", B = "<<t.second<<", C = "<<t.third<<endl;
		visit[t.first][t.second][t.third] = 1;
		if(t.first == 0)
		{
			AddToVector(t.third);
		}
		
		if((t.first>0)&&(B-t.second>0))//A->B�� ���� ��
		{
		 	//B�� ������� �� Ŭ ��
			if((B-t.second)>=t.first)
			{
				tmp.second = t.second+t.first;
				tmp.first = 0;
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			} 
			else if((B-t.second)<t.first)//B�� ��ä��� A�� ������ 
			{
				tmp.second = B;
				tmp.first = t.first - (B-t.second);
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.first>0)&&(C-t.third>0))//A->C�� ���� ��
		{
		 	//C�� ������� �� Ŭ ��
			if((C-t.third)>=t.first)
			{
				tmp.third = t.third+t.first;
				tmp.first = 0;
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			} 
			else if((C-t.third)<t.first)//C�� ��ä��� A�� ������ 
			{
				tmp.third = C;
				tmp.first = t.first - (C-t.third);
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.second>0)&&(A-t.first>0))//B->A�� ���� �� 
		{
			if((A-t.first)>=t.second)//A�� ������� �� Ŭ �� 
			{
				tmp.first = t.first+t.second;
				tmp.second = 0;
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((A-t.first)<t.second)//A�� ��ä��� B�� ������ 
			{
				tmp.first = A;
				tmp.second = t.second - (A-t.first);
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.second>0)&&(C-t.third>0))//B->C�� ���� �� 
		{
			if((C-t.third)>=t.second)//C�� ������� �� Ŭ�� 
			{
				tmp.third = t.third+t.second;
				tmp.second = 0;
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((C-t.third)<t.second)//C�� ä��� B�� ������ 
			{
				tmp.third = C;
				tmp.second = t.second - (C-t.third);
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.third>0)&&(A-t.first>0))//C->A�� ���� �� 
		{
			if((A-t.first)>=t.third)//A�� ������� �� Ŭ �� 
			{
				tmp.first = t.first+t.third;
				tmp.third = 0;
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((A-t.first)<t.third)//A�� ä��� C�� ������ 
			{
				tmp.first = A;
				tmp.third = t.third - (A-t.first);
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.third>0)&&(B-t.second>0))//C->B�� ���� �� 
		{
			if((B-t.second)>=t.third)//B�� ������� �� Ŭ �� 
			{
				tmp.second = t.second+t.third;
				tmp.third = 0;
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((B-t.second)<t.third)//B�� ä��� C�� ������ 
			{
				tmp.second = B;
				tmp.third = t.third - (B-t.second);
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
	}
}

int main(void)
{
	cin>>A>>B>>C;
	triple t;
	t.first = 0;
	t.second = 0;
	t.third = C;
	
	q.push(t);
	BFS();
	sort(v.begin(),v.end());
	
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}
