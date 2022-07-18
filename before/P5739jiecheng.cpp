#include<iostream>
#include<cstdio>
using namespace std;
int jie(int n);
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",jie(n));
	return 0;
}
int jie(int n){
	if(n==1) return 1;
	else return n*jie(n-1);
}
