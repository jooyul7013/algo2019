/*
����
�� ���� A�� B�� �Է¹��� ����, A/B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A�� B�� �־�����. (0 < A, B < 10)

���
ù° �ٿ� A/B�� ����Ѵ�. ����/��� ������ 10-9 ���� ����Ѵ�.*/

#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	
	double A, B;
	cin>>A>>B;
	cout<<fixed; 
	cout.precision(9);//�Ҽ��� 9°�ڸ����� ���� 
	cout<<A/B;
	return 0;
}
