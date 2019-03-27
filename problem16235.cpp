#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;

int N, M, K;
int result = 0;
int plus_m[11][11] = {0};

typedef struct tree{ 
	int old;//나무나이 
	bool alive;
}tree;//나무구조체 

typedef struct land{
	int first;
	vector<tree> v;
}land;

land map[11][11];

bool comp(tree &a, tree &b)
{
	return(a.old < b.old);
} 

int main(void)
{
	cin>>N>>M>>K;
	int x, y;
	tree t;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>plus_m[i][j];//양분표 
			map[i][j].first = 5;//현재 땅의 양분상태 초기화 
		}
	}
	
	for(int i=0; i<M; i++)
	{
		cin>>x>>y>>t.old;
		x -= 1;
		y -= 1;
		t.alive = 1;
		map[x][y].v.push_back(t);
	}
	
	
	
	for(int z=0; z<K; z++)
	{
		//봄
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(map[i][j].v.size()>0)
					sort(map[i][j].v.begin(), map[i][j].v.end(), comp);// 땅에 있는 나무 정렬
					
				for(int l=0; l<map[i][j].v.size(); l++)
				{
					if(map[i][j].first>=map[i][j].v[l].old)//빨아먹을 양분이 있을 때, 
					{
						map[i][j].first-=map[i][j].v[l].old;
						map[i][j].v[l].old++;//나무 나이 증가	
					}
					else
					{
						map[i][j].v[l].alive = 0;//나무 죽임 
					}
				} 
			}
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				for(int l=0; l<map[i][j].v.size();)
				{
					if(map[i][j].v[l].alive == 0)//빨아먹을 양분이 있을 때, 
					{
						map[i][j].first+=map[i][j].v[l].old/2;
						map[i][j].v.erase(map[i][j].v.begin()+l);//나무 나이 증가	
					}
					else
					{
						l++;//나무 죽임 
					}
				} 
			}
		}
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				for(int l=0; l<map[i][j].v.size(); l++)
				{
					if(map[i][j].v[l].old % 5 == 0)//번식가능한 나무일 때, 
					{
						if(i>0&&j>0)
						{
							t.alive = 1;
							t.old = 1;
							map[i-1][j-1].v.push_back(t);
						} 
						if(i>0)
						{
							t.alive = 1;
							t.old = 1;
							map[i-1][j].v.push_back(t);
						}
						if(i>0&&j<N-1)
						{
							t.alive = 1;
							t.old = 1;
							map[i-1][j+1].v.push_back(t);
						}
						if(j>0)
						{
							t.alive = 1;
							t.old = 1;
							map[i][j-1].v.push_back(t);
						}
						if(j<N-1)
						{
							t.alive = 1;
							t.old = 1;
							map[i][j+1].v.push_back(t);
						}
						if(i<N-1&&j>0)
						{
							t.alive = 1;
							t.old = 1;
							map[i+1][j-1].v.push_back(t);
						}
						if(i<N-1)
						{
							t.alive = 1;
							t.old = 1;
							map[i+1][j].v.push_back(t);
						}
						if(i<N-1&&j<N-1)
						{
							t.alive = 1;
							t.old = 1;
							map[i+1][j+1].v.push_back(t);
						}
					}
				} 
			}
		}
		
		for(int i=0; i<N; i++)
		{	
			for(int j=0; j<N; j++)
			{ 
				map[i][j].first += plus_m[i][j];//현재 땅의 양분상태 초기화 
			}
		}
	}
	/*cout<<endl;
	
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i].first<<"/"<<v[i].second<<"/"<<v[i].third<<endl;
		cout<<endl;
	}*/
	for(int i=0; i<N; i++)
	{	
		for(int j=0; j<N; j++)
		{ 
			result += map[i][j].v.size();//현재 땅의 양분상태 초기화 
		}
	}
	
	cout<<result<<endl;
}
