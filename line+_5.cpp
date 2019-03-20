#include <iostream>
#include <queue>
#include <vector>
#include <utility> 

using namespace std;

vector<int> koni;
queue<pair<int, int>> q;//브라운의 위치와 초를 나타낼 큐 

int k;//코니의 시작위치 
int b;//브라운의 시작위치 
int catchTime = -1;

int main(void)
{
	cin>>k>>b;
	koni.push_back(k);
	int i = 1;
	pair<int, int> p;
	while(k<=200000)
	{
		k= k+i;
		koni.push_back(k);
		i++;
	}
	p.first = b;
	p.second = 0;
	q.push(p);
	while(!q.empty())
	{
		pair<int, int> tmp = q.front();
		q.pop();
		if(koni.size()<tmp.second)//코니가 나가는 시간 체크 
		{
			break;//시간이 초과해버리는 순간 더 돌필요 없이 바로 끝나게 함 
		}
		
		if(koni[tmp.second]==tmp.first)
		{
			catchTime = tmp.second;
			break;
		}
		
		if(tmp.first>1)
		{
			p.first = tmp.first-1;
			p.second = tmp.second+1;
			q.push(p);
		}
		
		if(tmp.first <200000)
		{
			p.first = tmp.first+1;
			p.second = tmp.second+1;
			q.push(p);
		}
		
		if(tmp.first*2 <=200000)
		{
			p.first = tmp.first*2;
			p.second = tmp.second+1;
			q.push(p);
		}
	}
	
	cout<<catchTime<<endl;
}
