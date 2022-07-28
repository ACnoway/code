#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	float money[11]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65},all=0;
	int a;
	for(int i=0;i<10;i++){
		cin>>a;
		money[i]=money[i]*a;
		all+=money[i];
	}
	printf("%.1f",all);
	return 0;
}

