#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct triple{
	int first;
	int second;
	int third;
}triple;

int N;
int map[21][21] = {0};
bool visit[21][21] = {0};
int c_size = 2;//�����ũ�� 
int e_cnt = 0;//���� ���̼� 
int c_time = 0;//�ð� 
vector<triple> v;//���� �� �ִ� ����� ��ǥ ���� ���� �� �� vector 
queue<triple> q;//Ž���� ���� queue 

bool comp(triple a, triple b) 
{
	if(a.third<b.third)//�Ÿ� ������ ���� �� 
	{
		return true;
	}
	else if(a.third == b.third)
	{
		if(a.first<b.first)//���� �Ÿ��� ��� ���� �켱 
		{
			return true;
		}
		else if(a.first == b.first) 
		{
			if(a.second<b.second)//���̰� ���� ��� ���� ���� 
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		return false;
	} 
}

void BFS()
{
	triple t;
	triple tmp;
	while(!q.empty())
	{
		t = q.front();
		//visit[t.first][t.second] = 1;
		q.pop();
		if(map[t.first][t.second]>0&&map[t.first][t.second]<c_size)//���� �� �ִ� ��� 
		{
			v.push_back(t);//vector�� �߰� 
		} 
		
		//��
		if(t.first>0&&visit[t.first-1][t.second]==0&&map[t.first-1][t.second]<=c_size)
		{
			tmp.first = t.first-1;
			tmp.second = t.second;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		} 
		//��
		if(t.second>0&&visit[t.first][t.second-1]==0&&map[t.first][t.second-1]<=c_size)
		{
			tmp.first = t.first;
			tmp.second = t.second-1;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		}		
		//�Ʒ�
		if(t.first<N-1&&visit[t.first+1][t.second]==0&&map[t.first+1][t.second]<=c_size)
		{
			tmp.first = t.first+1;
			tmp.second = t.second;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		}
		//�� 
		if(t.second<N-1&&visit[t.first][t.second+1]==0&&map[t.first][t.second+1]<=c_size)
		{
			tmp.first = t.first;
			tmp.second = t.second+1;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		}
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			visit[i][j] = 0;
		}
	}
}

int main(void)
{
	triple t;
	cin>>N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>map[i][j];
			if(map[i][j] == 9)
			{
				t.first = i;
				t.second = j;
				t.third = 0;
				map[i][j] = 0;
				visit[t.first][t.second] = 1;
				q.push(t);
			}
		}
	}//���� �ٴٻ�Ȳ 
	
	while(1)
	{
		BFS();
		
		if(v.empty()==true)
		{
			break;
		}//���� ����Ⱑ ���� ��� Ž�� ��.
		else//���� ����Ⱑ �ִ� ��� 
		{
			sort(v.begin(),v.end(), comp);
			map[t.first][t.second] = 0;
			map[v[0].first][v[0].second] = 0;
			c_time+=v[0].third;
			e_cnt++;
			if(e_cnt == c_size)
			{
				c_size++;
				e_cnt = 0;
			}
			t.first = v[0].first;
			t.second = v[0].second;
			t.third = 0;
			visit[t.first][t.second] = 1;
			q.push(t);
			v.clear();
		} 
	}
	
	cout<<c_time<<endl;
}
