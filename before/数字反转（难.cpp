#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<0){  //�жϸ��� 
		cout<<"-";  //ȡ���� 
		n=-n;  //תΪ���������ڽ������ĳ��� 
	}
	if(n%10==0) n=n/10;  //�жϽ�β����0 
	int sum=0;
	while (n!=0)
	{
		int k=n%10;  //ȡn�ĸ�λ 
		sum=sum*10+k;  //��ֵ���Լӷ��ķ�ʽ������ʡ����0��ʱ�� 
		n=n/10; //������λ 
	}
	cout<<sum;
	return 0;
}
