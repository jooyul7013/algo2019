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

int BFS(int x, int y)
{
	triple tmp;
	triple p;
	int tmp_d = 41;
	while(!q.empty())
	{
		p = q.front();
		if(p.first == x&& p.second ==y)
		{
			if(tmp_d>p.third)
				tmp_d = p.third;
		}
		visit[p.first][p.second] = 1;
		q.pop();
		//��
		if(p.second>0&&visit[p.first][p.second-1] == 0&&map[p.first][p.second-1]<=c_size)
		{
			tmp.first = p.first;
			tmp.second = p.second-1;
			tmp.third = p.third+1;
			q.push(tmp);
		}
		
		if(p.first>0&&visit[p.first-1][p.second]== 0&&map[p.first-1][p.second]<=c_size)
		{
			tmp.first = p.first-1;
			tmp.second = p.second;
			tmp.third = p.third+1;
			q.push(tmp);
		}
		 
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
	
	for(int i = 0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			visit[i][j] = 0;
		}
	}
	
	if(tmp_d == 41)
		return -1;
	else
		return tmp_d;
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
				visit[x][y] = 1;
				tmp_dist = BFS(i,j);
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
		map[tmp_x][tmp_y] = 0;
		visit[tmp_x][tmp_y] = 1;//�����ڸ� ��� �ű� 
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
	int x, y;//i,j
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>map[i][j];
			if(map[i][j] == 9)
			{
				map[i][j] = 0;
				x = i;
				y = j;
	//			cout<<x<<y<<endl;
			} 
		}
	}
	visit[x][y] = 1;
	DFS(x,y);
	
	cout<<c_time<<endl;
}
