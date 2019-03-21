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
int c_size = 2;//물고기크기 
int e_cnt = 0;//먹은 먹이수 
int c_time = 0;//시간 
vector<triple> v;//먹을 수 있는 물고기 좌표 쌍을 저장 해 둘 vector 
queue<triple> q;//탐색에 쓰일 queue 

bool comp(triple a, triple b) 
{
	if(a.third<b.third)//거리 순으로 먼저 비교 
	{
		return true;
	}
	else if(a.third == b.third)
	{
		if(a.first<b.first)//같은 거리일 경우 높이 우선 
		{
			return true;
		}
		else if(a.first == b.first) 
		{
			if(a.second<b.second)//높이가 같을 경우 왼쪽 선택 
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
		if(map[t.first][t.second]>0&&map[t.first][t.second]<c_size)//먹을 수 있는 경우 
		{
			v.push_back(t);//vector에 추가 
		} 
		
		//위
		if(t.first>0&&visit[t.first-1][t.second]==0&&map[t.first-1][t.second]<=c_size)
		{
			tmp.first = t.first-1;
			tmp.second = t.second;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		} 
		//왼
		if(t.second>0&&visit[t.first][t.second-1]==0&&map[t.first][t.second-1]<=c_size)
		{
			tmp.first = t.first;
			tmp.second = t.second-1;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		}		
		//아래
		if(t.first<N-1&&visit[t.first+1][t.second]==0&&map[t.first+1][t.second]<=c_size)
		{
			tmp.first = t.first+1;
			tmp.second = t.second;
			tmp.third = t.third+1;
			visit[tmp.first][tmp.second] = 1;
			q.push(tmp);
		}
		//오 
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
	}//현재 바다상황 
	
	while(1)
	{
		BFS();
		
		if(v.empty()==true)
		{
			break;
		}//먹을 물고기가 없는 경우 탐색 끝.
		else//먹을 물고기가 있는 경우 
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
