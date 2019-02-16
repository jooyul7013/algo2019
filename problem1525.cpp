#include <iostream>
#include <vector>

using namespace std;
vector<int*> v;
int arr[9] = {0};
int flag = 99999;
int vectorsize = 0;

bool check()
{
	for(int i=0; i<8; i++)
	{
		if(arr[i]==i+1)
			continue;
		else
			return false;
	}
	return true;
}

bool vectorcheck()
{
	bool visit = false;
	int count;
	for(int i = 0; i<vectorsize; i++)
	{
		count  = 0;
		for(int j=0; j<9; j++)
		{
			if(v[i][j] == arr[j])
			{
				count++;
			}
			if(count == 9)
			{
				visit =  true;
			}
		}
	}
	return visit;
}

void DFS(int count)
{
	int tmp;
	//cout<<count<<endl;
	if(check() == true)
	{
		flag = count;
		return;
	}
	
	for(int i=0; i<9; i++)
	{
		if(arr[i] == 0)//checkpoint
		{
			if(i!=0&&i!=3&&i!=6)
			{
				tmp = arr[i-1];
				arr[i-1] = 0;
				arr[i] = tmp;//swap
				
				if(vectorcheck()==false)
				{
					int tmparr[9] = {0};
					for(int j =0; j<9; j++)
					{
						tmparr[j] = arr[j];
					}
					v.push_back(tmparr);
					vectorsize++;
					DFS(count+1);
				}
				arr[i-1] = tmp;
				arr[i] = 0;
			}
			if(i>2)
			{
				tmp = arr[i-3];
				arr[i-3] = 0;
				arr[i] = tmp;//swap
				
				if(vectorcheck()==false)
				{
					int tmparr[9] = {0};
					for(int j =0; j<9; j++)
					{
						tmparr[j] = arr[j];
					}
					v.push_back(tmparr);
					vectorsize++;
					DFS(count+1);
				}
				arr[i-3] = tmp;
				arr[i] = 0;
			}
			if(i!=8&&i!=5&&i!=2)
			{
				tmp = arr[i+1];
				arr[i+1] = 0;
				arr[i] = tmp;//swap
				
				if(vectorcheck()==false)
				{
					int tmparr[9] = {0};
					for(int j =0; j<9; j++)
					{
						tmparr[j] = arr[j];
					}
					v.push_back(tmparr);
					vectorsize++;
					DFS(count+1);
				}
				arr[i+1] = tmp;
				arr[i] = 0;
			}
			if(i<6)
			{
				tmp = arr[i+3];
				arr[i+3] = 0;
				arr[i] = tmp;//swap
				
				if(vectorcheck()==false)
				{
					int tmparr[9] = {0};
					for(int j =0; j<9; j++)
					{
						tmparr[j] = arr[j];
					}
					v.push_back(tmparr);
					vectorsize++;
					DFS(count+1);
				}
				arr[i+3] = tmp;
				arr[i] = 0;
			}
		}
	}
}



int main(void)
{
	int tmparr[9] = {0};
	for(int i=0; i<9; i++)
	{
		cin>>arr[i];
		tmparr[i] = arr[i];
	}
	v.push_back(tmparr);
	vectorsize++;
	
	DFS(0);
	cout<<flag;	
}
