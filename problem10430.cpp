/*
����
(A+B)%C�� (A%C + B%C)%C �� ������?

(A��B)%C�� (A%C �� B%C)%C �� ������?

�� �� A, B, C�� �־����� ��, ���� �� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A, B, C�� ������� �־�����. (2 �� A, B, C �� 10000)

���
ù° �ٿ� (A+B)%C, ��° �ٿ� (A%C + B%C)%C, ��° �ٿ� (A��B)%C, ��° �ٿ� (A%C �� B%C)%C�� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;
	cin>>A>>B>>C;
	
	cout<<(A+B)%C<<endl;
	cout<<(A%C+B%C)%C<<endl;
	cout<<(A*B)%C<<endl;
	cout<<(A%C*B%C)%C<<endl;
	
	return 0;
}
