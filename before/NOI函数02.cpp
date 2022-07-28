#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int times(int zi){
	if(zi>70){
		zi-=70;
		if(zi%70!=0){
			return zi/70+1;
		}
		else return zi/70;
	}
	else return 0;
}
int main()
{
	int n,money,time=0;
	cin>>n;
	time=n;
	for(int i=0;i<n;i++){
		int zs;
		cin>>zs;
		time+=times(zs);
	}
	printf("%.1f",time*0.1);
	return 0;
}

