#include <iostream>

using namespace std;

int main(void)
{
	int arr[3];
	int tmp = 0;
	
	cin>>arr[0]>>arr[1]>>arr[2];
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(arr[j]<arr[j+1])
			{
				tmp = arr[j];
				arr[j]= arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	cout<<arr[1];
}
