#include<iostream>
#include<cstdio>
#include<cmath>
#include<time.h>
using namespace std;
int main()
{
	int n,a=2,b=2,c=2,d=2;
	clock_t begin,stop;
	cin>>n;
	begin=clock();
	for(a=2;a<=n;a++){
		for(b=2;b<=n;b++){
			for(c=b;c<=n;c++){
				for(d=c;d<=n;d++){
					if(pow(a,3)==(pow(b,3)+pow(c,3)+pow(d,3))){
						cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
					}
				}
			}
		}
	}
	stop=clock();
	cout<<stop-begin;
	return 0;
}

