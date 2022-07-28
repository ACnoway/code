#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int jj=0,mom=0,m=300,left=0,ys[13];
	for(int i=1;i<=12;i++){
		cin>>ys[i];
	}
	for(int i=1;i<=12;i++){
		left+=m-ys[i];
		if(left<0){
			cout<<"-"<<i;
			return 0;
		}
		if(left/100){
			mom+=left/100*100;
			left-=left/100*100;
			
		}
	}
	left+=mom*1.2;
	cout<<left;
	return 0;
}

