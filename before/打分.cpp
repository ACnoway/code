#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double n,big=0,small=11,add=0,score[1001];
	cin>>n;
	for(int i=0;i<n;i++){//��ȡ���� 
		double a;
		cin>>a;
		add+=a; //�����ܺ� 
		if(a>big) big=a; //��߷� 
		if(a<small) small=a; //��ͷ� 
	}
	if(n>2){
		add=add-big-small; //��ȥ��߷ֺ���ͷ� 
		cout<<fixed<<setprecision(2)<<add/(n-2); //��� 
	}
	else if(n==2) cout<<fixed<<setprecision(2)<<add/n; //���ڶ�ʱֱ�ӳ�2 
	else if(n==1) cout<<add; //����һʱֱ����� 
	else cout<<"0";
	return 0;
}

