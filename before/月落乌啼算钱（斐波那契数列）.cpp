#include<iostream>
#include<cstdio>
#include<cmath>
const double WU=sqrt(5);
using namespace std;
int main()
{
	int n;
	cin>>n;
	double f;
	f=(pow((1.00+WU)/2.00,n)-pow((1.00-WU)/2.00,n))/WU;
	printf("%.2lf",f);
    return 0;
}

