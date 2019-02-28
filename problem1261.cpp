#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef struct triple{
	int first;
	int second;
	int cnt;
}triple; 
queue<triple> q;
int N, M;
int brkCnt = 9999;//부순 횟수(최소가 되도록 계속 업데이트 할 변수) 
int brkCheck[101][101];
bool arr[101][101] = {0};
bool visit[101][101] = {0};
triple t;

void BFS()
{
	triple loc;
	triple tmp;
	while(!q.empty())
	{
		loc = q.front();
		tmp = q.front();
		q.pop();
		
		if(loc.first == N-1 && loc.second == M-1)
		{
			if(loc.cnt <brkCnt)
				brkCnt = loc.cnt;
		}
		//좌 
		if(loc.first>0)//좌측으로 갈 수 있으면서,  
		{
			if(arr[loc.first-1][loc.second] == 0)//뚫린 방인 경우 
			{
				tmp.first = loc.first-1;
				tmp.second = loc.second;
				tmp.cnt = loc.cnt;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
			else
			{
				tmp.first = loc.first-1;
				tmp.second = loc.second;
				tmp.cnt = loc.cnt+1;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
		}
		//우
		if(loc.first<N-1)//좌측으로 갈 수 있으면서,  
		{
			if(arr[loc.first+1][loc.second] == 0)//뚫린 방인 경우 
			{
				tmp.first = loc.first+1;
				tmp.second = loc.second;
				tmp.cnt = loc.cnt;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				} 
			}
			else
			{
				tmp.first = loc.first+1;
				tmp.second = loc.second;
				tmp.cnt = loc.cnt+1;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
		}
		//위
		if(loc.second>0)
		{
			if(arr[loc.first][loc.second-1] == 0)
			{
				tmp.first = loc.first;
				tmp.second = loc.second-1;
				tmp.cnt = loc.cnt;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
			else
			{
				tmp.first = loc.first;
				tmp.second = loc.second-1;
				tmp.cnt = loc.cnt+1;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
		}
		//아래 
		if(loc.second<M-1)
		{
			if(arr[loc.first][loc.second+1] == 0)
			{
				tmp.first = loc.first;
				tmp.second = loc.second+1;
				tmp.cnt = loc.cnt;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
			else
			{
				tmp.first = loc.first;
				tmp.second = loc.second+1;
				tmp.cnt = loc.cnt+1;
				if(brkCheck[tmp.first][tmp.second]>tmp.cnt)
				{
					brkCheck[tmp.first][tmp.second] = tmp.cnt;
					q.push(tmp);
				}
			}
		}
	}
} 

int main(void)
{
	cin>>M>>N;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for(int i=0; i<101; i++)
	{
		for(int j=0; j<101; j++)
		{
			brkCheck[i][j] = 99999;
		}
	}
	brkCheck[0][0] = 0;
	t.first = 0;
	t.second = 0;
	t.cnt = 0; 
	q.push(t);
	BFS();
	
	cout<<brkCnt<<endl;
}
