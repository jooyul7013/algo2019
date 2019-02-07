/*
문제
두 정수 A와 B를 입력받은 다음, A/B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
첫째 줄에 A/B를 출력한다. 절대/상대 오차는 10-9 까지 허용한다.*/

#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	
	double A, B;
	cin>>A>>B;
	cout<<fixed; 
	cout.precision(9);//소수점 9째자리까지 지정 
	cout<<A/B;
	return 0;
}
