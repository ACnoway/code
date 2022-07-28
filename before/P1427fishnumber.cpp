#include<cstdio>
#include<iostream>
using namespace std;
int a[100];
int main()
{
    int x,n=0;
    while(true){
    	cin>>x;
    	if(x==0) break;
		else a[n++]=x;
	}
    for(int i=n-1;i>=1;i--)
    	printf("%d ",a[i]);
    printf("%d",a[0]);
    return 0;
}


