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
		
		if((t.first>0)&&(B-t.second>0))//A->B로 부을 때
		{
		 	//B의 빈공간이 더 클 때
			if((B-t.second)>=t.first)
			{
				tmp.second = t.second+t.first;
				tmp.first = 0;
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			} 
			else if((B-t.second)<t.first)//B를 꽉채우고도 A가 남을때 
			{
				tmp.second = B;
				tmp.first = t.first - (B-t.second);
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.first>0)&&(C-t.third>0))//A->C로 부을 때
		{
		 	//C의 빈공간이 더 클 때
			if((C-t.third)>=t.first)
			{
				tmp.third = t.third+t.first;
				tmp.first = 0;
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			} 
			else if((C-t.third)<t.first)//C를 꽉채우고도 A가 남을때 
			{
				tmp.third = C;
				tmp.first = t.first - (C-t.third);
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.second>0)&&(A-t.first>0))//B->A로 부을 때 
		{
			if((A-t.first)>=t.second)//A의 빈공간이 더 클 때 
			{
				tmp.first = t.first+t.second;
				tmp.second = 0;
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((A-t.first)<t.second)//A를 꽉채우고도 B가 남을때 
			{
				tmp.first = A;
				tmp.second = t.second - (A-t.first);
				tmp.third = t.third;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.second>0)&&(C-t.third>0))//B->C로 부을 때 
		{
			if((C-t.third)>=t.second)//C의 빈공간이 더 클때 
			{
				tmp.third = t.third+t.second;
				tmp.second = 0;
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((C-t.third)<t.second)//C를 채우고 B가 남을때 
			{
				tmp.third = C;
				tmp.second = t.second - (C-t.third);
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.third>0)&&(A-t.first>0))//C->A로 부을 때 
		{
			if((A-t.first)>=t.third)//A의 빈공간이 더 클 때 
			{
				tmp.first = t.first+t.third;
				tmp.third = 0;
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((A-t.first)<t.third)//A를 채우고 C가 남을때 
			{
				tmp.first = A;
				tmp.third = t.third - (A-t.first);
				tmp.second = t.second;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
		}
		if((t.third>0)&&(B-t.second>0))//C->B로 부을 때 
		{
			if((B-t.second)>=t.third)//B의 빈공간이 더 클 때 
			{
				tmp.second = t.second+t.third;
				tmp.third = 0;
				tmp.first = t.first;
				if(visit[tmp.first][tmp.second][tmp.third]==0)
					q.push(tmp);
			}
			else if((B-t.second)<t.third)//B를 채우고 C가 남을때 
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
