#include <iostream>

using namespace std;

int main(void)
{
	int month_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	string day_of_week[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int x,y;
	int total_days = 0;
	cin>>x>>y;
	
	for(int i=0; i<x; i++)
	{
		total_days = total_days+month_day[i];
	}
	total_days+=y;
	
	cout<<day_of_week[total_days%7];
	
	return 0;
}
