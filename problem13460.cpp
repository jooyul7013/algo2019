#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

typedef struct balls
{
	int r1;
	int r2;
	int b1;
	int b2;
	int cnt;
	int before;
}balls;

queue<balls> q;
int N, M;
int result = 11;
char map[20][20] = { 0 };
int target1, target2;//구멍의 좌표 

balls move(balls b, int c)
{
	if ((b.r1 == target1 && b.r2 == target2) || (b.b1 == target1 && b.b2 == target2))
		return b;

	switch (c) {
	case 1://상
		if (b.r1 > b.b1)//파란공이 위에 있을 때, 파란공 먼저. 
		{
			for (int i = b.b1; i >= 0; i--)
			{
				if (map[i][b.b2] == 'O')
				{
					b.b1 = i;
					break;
				}
				if (i == b.r1&&b.b2 == b.r2)
				{
					b.b1 = i + 1;
					break;
				}
				if (map[i][b.b2] == '.')
					continue;
				if (map[i][b.b2] == '#')
				{
					b.b1 = i + 1;
					break;
				}
			}
			for (int i = b.r1; i >= 0; i--)
			{
				if (map[i][b.r2] == 'O')
				{
					b.r1 = i;
					break;
				}
				if (i == b.b1&&b.b2 == b.r2)
				{
					b.r1 = i + 1;
					break;
				}
				if (map[i][b.r2] == '.')
					continue;
				if (map[i][b.r2] == '#')
				{
					b.r1 = i + 1;
					break;
				}
			}
		}
		else if (b.r1 <= b.b1)
		{
			for (int i = b.r1; i >= 0; i--)
			{
				if (map[i][b.r2] == 'O')
				{
					b.r1 = i;
					break;
				}
				if (i == b.b1&&b.b2 == b.r2)
				{
					b.r1 = i + 1;
					break;
				}
				if (map[i][b.r2] == '.')
					continue;
				if (map[i][b.r2] == '#')
				{
					b.r1 = i + 1;
					break;
				}
			}
			for (int i = b.b1; i >= 0; i--)
			{
				if (map[i][b.b2] == 'O')
				{
					b.b1 = i;
					break;
				}
				if (i == b.r1&&b.b2 == b.r2)
				{
					b.b1 = i + 1;
					break;
				}
				if (map[i][b.b2] == '.')
					continue;
				if (map[i][b.b2] == '#')
				{
					b.b1 = i + 1;
					break;
				}
			}
		}
		break;
	case 2://하
		if (b.r1 > b.b1)//큰거부터 증가 
		{
			for (int i = b.r1; i < N; i++)
			{
				if (map[i][b.r2] == 'O')
				{
					b.r1 = i;
					break;
				}
				if (i == b.b1&&b.r2 == b.b2)
				{
					b.r1 = i - 1;
					break;
				}
				if (map[i][b.r2] == '.')
					continue;
				if (map[i][b.r2] == '#')
				{
					b.r1 = i - 1;
					break;
				}
			}
			for (int i = b.b1; i < N; i++)
			{
				if (map[i][b.b2] == 'O')
				{
					b.b1 = i;
					break;
				}
				if (i == b.r1&&b.r2 == b.b2)
				{
					b.b1 = i - 1;
					break;
				}
				if (map[i][b.b2] == '.')
					continue;
				if (map[i][b.b2] == '#')
				{
					b.b1 = i - 1;
					break;
				}
			}
		}
		else if (b.r1 <= b.b1)
		{
			for (int i = b.b1; i < N; i++)
			{
				if (map[i][b.b2] == 'O')
				{
					b.b1 = i;
					break;
				}
				if (i == b.r1&&b.r2 == b.b2)
				{
					b.b1 = i - 1;
					break;
				}
				if (map[i][b.b2] == '.')
					continue;
				if (map[i][b.b2] == '#')
				{
					b.b1 = i - 1;
					break;
				}
			}
			for (int i = b.r1; i < N; i++)
			{
				if (map[i][b.r2] == 'O')
				{
					b.r1 = i;
					break;
				}
				if (i == b.b1&&b.r2 == b.b2)
				{
					b.r1 = i - 1;
					break;
				}
				if (map[i][b.r2] == '.')
					continue;
				if (map[i][b.r2] == '#')
				{
					b.r1 = i - 1;
					break;
				}
			}
		}
		break;
	case 3://좌 
		if (b.r2 > b.b2)
		{
			//b먼저
			for (int i = b.b2; i >= 0; i--)
			{
				if (map[b.b1][i] == 'O')
				{
					b.b2 = i;
					break;
				}
				if (i == b.r2&&b.r1 == b.b2)
				{
					b.b2 = i + 1;
					break;
				}
				if (map[b.b1][i] == '.')
					continue;

				if (map[b.b1][i] == '#')
				{
					b.b2 = i + 1;
					break;
				}
			}
			for (int i = b.r2; i >= 0; i--)
			{
				if (map[b.r1][i] == 'O')
				{
					b.r2 = i;
					break;
				}
				if (i == b.b2&&b.r1 == b.b2)
				{
					b.r2 = i + 1;
					break;
				}
				if (map[b.r1][i] == '.')
					continue;
				if (map[b.r1][i] == '#')
				{
					b.r2 = i + 1;
					break;
				}
			}
		}
		else if (b.r2 <= b.b2)
		{
			//r먼저
			for (int i = b.r2; i >= 0; i--)
			{
				if (map[b.r1][i] == 'O')
				{
					b.r2 = i;
					break;
				}
				if (i == b.b2&&b.r1 == b.b1)
				{
					b.r2 = i + 1;
					break;
				}
				if (map[b.r1][i] == '.')
					continue;

				if (map[b.r1][i] == '#')
				{
					b.r2 = i + 1;
					break;
				}
			}
			for (int i = b.b2; i >= 0; i--)
			{
				if (map[b.b1][i] == 'O')
				{
					b.b2 = i;
					break;
				}
				if (i == b.r2&&b.r1 == b.b1)
				{
					b.b2 = i + 1;
					break;
				}
				if (map[b.b1][i] == '.')
					continue;
				if (map[b.b1][i] == '#')
				{
					b.b2 = i + 1;
					break;
				}
			}
		}
		break;
	case 4:	//우
		if (b.r2 > b.b2)
		{
			//r먼저
			for (int i = b.r2; i < M; i++)
			{
				if (map[b.r1][i] == 'O')
				{
					b.r2 = i;
					break;
				}
				if (i == b.b2&&b.r1 == b.b1)
				{
					b.r2 = i - 1;
					break;
				}
				if (map[b.r1][i] == '.')
					continue;
				if (map[b.r1][i] == '#')
				{
					b.r2 = i - 1;
					break;
				}
			}
			for (int i = b.b2; i < M; i++)
			{
				if (map[b.b1][i] == 'O')
				{
					b.b2 = i;
					break;
				}
				if (i == b.r2&&b.r1 == b.b1)
				{
					b.b2 = i - 1;
					break;
				}
				if (map[b.b1][i] == '.')
					continue;
				if (map[b.b1][i] == '#')
				{
					b.b2 = i - 1;
					break;
				}
			}
		}
		else if (b.r2 <= b.b2)
		{
			//b먼저
			for (int i = b.b2; i < M; i++)
			{
				if (map[b.b1][i] == 'O')
				{
					b.b2 = i;
					break;
				}
				if (i == b.r2&&b.r1 == b.b1)
				{
					b.b2 = i - 1;
					break;
				}
				if (map[b.b1][i] == '.')
					continue;
				if (map[b.b1][i] == '#')
				{
					b.b2 = i - 1;
					break;
				}
			}
			for (int i = b.r2; i < M; i++)
			{
				if (map[b.r1][i] == 'O')
				{
					b.r2 = i;
					break;
				}
				if (i == b.b2&&b.r1 == b.b1)
				{
					b.r2 = i - 1;
					break;
				}
				if (map[b.r1][i] == '.')
					continue;
				if (map[b.r1][i] == '#')
				{
					b.r2 = i - 1;
					break;
				}
			}
		}
		break;
	}

	return b;
}

void BFS()
{
	balls ball1;
	balls tmp;
	while (!q.empty())
	{
		ball1 = q.front();
		q.pop();
		//	cout << "red = " << ball1.r1 << ", " << ball1.r2 << endl;
		//	cout << "blue = " << ball1.b1 << ", " << ball1.b2 << endl;
		if (ball1.cnt > 9)
		{
			result = -1;
			return;
		}
		if (ball1.r1 == target1 && ball1.r2 == target2)
		{
			if (ball1.b1 == target1 && ball1.b2 == target2)
				continue;
			else
			{
				//if(result > ball1.cnt)
				result = ball1.cnt;
				return;
			}
		}
		if (ball1.before != 1)//상 
		{
			tmp = move(ball1, 1);
			tmp.before = 1;
			tmp.cnt = ball1.cnt + 1;
			q.push(tmp);
		}
		if (ball1.before != 2)//하
		{
			tmp = move(ball1, 2);
			tmp.before = 2;
			tmp.cnt = ball1.cnt + 1;
			q.push(tmp);
		}
		if (ball1.before != 3)//하
		{
			tmp = move(ball1, 3);
			tmp.before = 3;
			tmp.cnt = ball1.cnt + 1;
			q.push(tmp);
		}
		
		if (ball1.before != 4)//하
		{
			tmp = move(ball1, 4);
			tmp.before = 4;
			tmp.cnt = ball1.cnt + 1;
			q.push(tmp);
		}
	}
}

int main(void)
{
	cin >> N >> M;
	getchar();
	balls b;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == N - 1 && j == M - 1)
				scanf("%1c", &map[i][j]);
			else
				scanf("%1c\n", &map[i][j]);

			if (j == M - 1)
			{
				//getchar();
				//getchar();
				//flush();
			}

			if (map[i][j] == 'B')
			{
				b.b1 = i;
				b.b2 = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'R')
			{
				b.r1 = i;
				b.r2 = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'O')
			{
				target1 = i;
				target2 = j;
			}
		}
	}
	//getchar();
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j == M - 1)
				cout << map[i][j] << endl;
			else
				cout << map[i][j];
		}
	}*/

	b.cnt = 0;
	b.before = 0;
	q.push(b);
	BFS();
	cout << result << endl;

//	scanf("%1c", &map[0][0]);
	//scanf("%1c", &map[0][0]);
	return 0;
}
