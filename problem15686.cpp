#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;
int map[50][50] = {0};
int visit[13] = {0};
int N, M;
int total_dist = 9999;

typedef struct triple{
	int first; //x좌표 
	int second; //y좌표 
	int third; //치킨거리 
}triple;

vector<triple> house;
vector<pair<int,int>> chk;//모든 치킨집이 들어있는 vector


void DFS(int depth)
{
	if(depth == M-1)
	{
		int tmp_dist = 0;
		for(int i=0; i<house.size(); i++)
		{
			house[i].third = 999;
			for(int j=0; j<M; j++)
			{
				int dist = abs(house[i].first-chk[visit[j]].first)+abs(house[i].second-chk[visit[j]].second);
				if(house[i].third > dist)
					house[i].third = dist;
			}
			tmp_dist+=house[i].third;
		}
		if(tmp_dist<total_dist)
			total_dist = tmp_dist;
	}
	else//치킨집 고르는 부분 
	{
		for(int i=visit[depth]+1; i<chk.size(); i++)
		{
			visit[depth+1] = i;
			DFS(depth+1);
		}
	}
}

int main(void)
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>map[i][j];
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]==1)
			{
				triple t;
				t.first = i;
				t.second = j;
				t.third = 100;
				house.push_back(t);
			}
			else if(map[i][j]==2)
			{
				pair<int, int> p;
				p.first = i;
				p.second = j;
				chk.push_back(p);
			}
		}
	}
	
	for(int i=0; i<chk.size(); i++)
	{
		visit[0] = i;
		DFS(0);
	}
		
	cout<<total_dist<<endl;
}
