#include <iostream>
#include <queue>
#include <vector>
#include <utility> 

using namespace std;

vector<int> koni;
queue<pair<int, int>> q;//������ ��ġ�� �ʸ� ��Ÿ�� ť 

int k;//�ڴ��� ������ġ 
int b;//������ ������ġ 
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
		if(koni.size()<tmp.second)//�ڴϰ� ������ �ð� üũ 
		{
			break;//�ð��� �ʰ��ع����� ���� �� ���ʿ� ���� �ٷ� ������ �� 
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
