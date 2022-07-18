#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	double A=0,a=0,B=0,b=0;
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		if(x%k==0){
			A+=x;
			a++; 
		}
		else{
			B+=x;
			b++;
		}
	}
	A/=a;
	B/=b;
	printf("%.1lf %.1lf",A,B);
	return 0;
}

