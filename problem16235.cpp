#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;

int N, M, K;
int result = 0;
int plus_m[11][11] = {0};

typedef struct tree{ 
	int old;//�������� 
	bool alive;
}tree;//��������ü 

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
			cin>>plus_m[i][j];//���ǥ 
			map[i][j].first = 5;//���� ���� ��л��� �ʱ�ȭ 
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
		//��
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(map[i][j].v.size()>0)
					sort(map[i][j].v.begin(), map[i][j].v.end(), comp);// ���� �ִ� ���� ����
					
				for(int l=0; l<map[i][j].v.size(); l++)
				{
					if(map[i][j].first>=map[i][j].v[l].old)//���Ƹ��� ����� ���� ��, 
					{
						map[i][j].first-=map[i][j].v[l].old;
						map[i][j].v[l].old++;//���� ���� ����	
					}
					else
					{
						map[i][j].v[l].alive = 0;//���� ���� 
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
					if(map[i][j].v[l].alive == 0)//���Ƹ��� ����� ���� ��, 
					{
						map[i][j].first+=map[i][j].v[l].old/2;
						map[i][j].v.erase(map[i][j].v.begin()+l);//���� ���� ����	
					}
					else
					{
						l++;//���� ���� 
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
					if(map[i][j].v[l].old % 5 == 0)//���İ����� ������ ��, 
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
				map[i][j].first += plus_m[i][j];//���� ���� ��л��� �ʱ�ȭ 
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
			result += map[i][j].v.size();//���� ���� ��л��� �ʱ�ȭ 
		}
	}
	
	cout<<result<<endl;
}
