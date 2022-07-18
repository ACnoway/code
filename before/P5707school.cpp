#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int m=10,h=0,hh=8,mm=0;
	double s,v;
	cin>>s>>v;
	m=m+ceil(s/v); h+=m/60; m-=h*60;
	if(m){
		mm=mm+60-m; hh--;
	}
	hh=hh-h;
	if(hh<0){
		hh+=24;
	}
	printf("%02d:%02d",hh,mm);
	return 0;
}

