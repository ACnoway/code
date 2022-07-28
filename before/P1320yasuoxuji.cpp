#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t0[40001],t1[40001];
int main()
{
	int a0=0,a1=0,n,flag=2,temp0=0,temp1=0,add=0;
	char sz;
	scanf("%c",&sz);
	flag=sz-'0';
	if(sz=='0') a0++;
	else{
		a1++; t0[temp0++]=0;
	}
	while(scanf("%c",&sz)==1){
		if(sz=='0'&&flag==0){
			a0++;
		}
		else if(sz=='0'&&flag==1){
			flag=0; a0++;
			t1[temp1++]=a1; add+=a1; a1=0;
		}
		else if(sz=='1'&&flag==0){
			flag=1; a1++;
			t0[temp0++]=a0; add+=a0; a0=0;
		}
		else if(sz=='1'&&flag==1){
			a1++;
		}
	}
	if(flag==1){
		add+=a1; t1[temp1++]=a1;
	}
	if(flag==0){
		add+=a0; t0[temp0++]=a0;
	}
	n=sqrt(add); cout<<n<<" ";
	for(int i=0;i<temp1;i++){
		printf("%d %d ",t0[i],t1[i]);
	}
	if(flag==0) cout<<t0[temp0-1];
	return 0;
}

