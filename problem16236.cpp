#include <iostream>
#include <math.h>
#include <queue>
#include <utility>

typedef struct triple
{
	int first;
	int second;
	int third;
}triple;
using namespace std;
queue<triple> q;

int visit[21][21] = {1};
int map[21][21] = {0};
int N;
int c_size = 2;//current_size
int e_cnt = 0;//eat_count
int c_time = 0;//current_time
int dist = 41;//distance between shark and fish
int x, y;

void BFS()
{
	triple tmp;
	triple p;
	while(!q.empty())
	{
		p = q.front();
		visit[p.first][p.second] = 1;
		q.pop();
		if(map[p.first][p.second]>0&&map[p.first][p.second]<c_size)//���� �� �ִ� ���, 
		{
			//cout<<"SIZE = "<<c_size<<endl;
			//cout<<"count = "<<e_cnt<<endl;
			/*cout<<"time = "<<c_time<<endl;
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<N; j++)
				{
					if(j == N-1)
					{
						cout<<map[i][j]<<endl;
					}
					else
						cout<<map[i][j]<<" ";
				}
			}*/
			
			map[p.first][p.second] = 9;
			map[x][y] = 0;//�����ڸ� 0 
			x = p.first;//
			y = p.second;//
			c_time+=p.third;
			p.third = 0;
			e_cnt++;
			if(e_cnt==c_size)
			{
				c_size++;
				e_cnt = 0;
			}
			for(int i = 0; i<N; i++)
			{
				for(int j=0; j<N; j++)
				{
					visit[i][j] = 0;
				}
			}
			visit[x][y] = 1;
			while(!q.empty())
				q.pop();
		}
		
		if(p.first>0&&visit[p.first-1][p.second]== 0&&map[p.first-1][p.second]<=c_size)
		{
			tmp.first = p.first-1;
			tmp.second = p.second;
			tmp.third = p.third+1;
			q.push(tmp);
		}
		
		if(p.second>0&&visit[p.first][p.second-1] == 0&&map[p.first][p.second-1]<=c_size)
		{
			tmp.first = p.first;
			tmp.second = p.second-1;
			tmp.third = p.third+1;
			q.push(tmp);
		}
		//���� 
		
		
		//�Ʒ�
		if(p.second<N-1&&visit[p.first][p.second+1] == 0&&map[p.first][p.second+1]<=c_size)
		{
			tmp.first = p.first;
			tmp.second = p.second+1;
			tmp.third = p.third+1;
			q.push(tmp);
		}	
		//�� 
		
		if(p.first<N-1&&visit[p.first+1][p.second]== 0&&map[p.first+1][p.second]<=c_size)
		{
			tmp.first = p.first+1;
			tmp.second = p.second;
			tmp.third = p.third+1;
			q.push(tmp);
		}

	}
}
void DFS(int x, int y)
{
	/*cout<<endl;
	cout<<"SIZE = "<<c_size<<endl;
	cout<<"count = "<<e_cnt<<endl;
	cout<<"time = "<<c_time<<endl;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(j == N-1)
			{
				cout<<map[i][j]<<endl;
			}
			else
			cout<<map[i][j]<<" ";
		}
	}*/
	int tmp_x = 55;
	int tmp_y = 55;//i,j�� ���
	int tmp_dist = 0; 
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]>0&&map[i][j]<c_size)//���� ����Ⱑ ���� ��. 
			{
				triple t;
				t.first = x;
				t.second = y;
				t.third = 0;
				q.push(t);
			//	tmp_dist = BFS(i,j);
				if(tmp_dist>0&&tmp_dist<dist)//������ ���� 
				{
					tmp_x = i;
					tmp_y = j;
					dist = tmp_dist;//�Ÿ� ���� 
				}
			}
		}
	}//�� for���� �������ö��� ���� ����� ������ �ִ� ����� ��ġ ��� 
	if(tmp_x == 55)
	{
		return;
	}
	else
	{
		map[x][y] = 0;//���� ��� �ڸ� ��ĭ���� 
		map[tmp_x][tmp_y] = 9;//�����ڸ� ��� �ű� 
		c_time += dist;//������ �Ÿ���ŭ �ð� ���� 
		dist = 41;//�ٽ� �Ÿ��� �ؾ��ϱ� ������ �ʱ�ȭ 
		e_cnt++;
		if(e_cnt == c_size)
		{
			c_size += 1;
			e_cnt = 0;
		}//����� �� ä������ ũ�� ���� 
		DFS(tmp_x, tmp_y); 
	}
}

int main(void)
{
	cin>>N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>map[i][j];
			if(map[i][j] == 9)
			{
				x = i;
				y = j;
			} 
		}
	}
	triple t;
	t.first = x;
	t.second = y;
	t.third = 0;
	visit[t.first][t.second] = 1;
	q.push(t);
	BFS();
	
	cout<<c_time<<endl;
}
