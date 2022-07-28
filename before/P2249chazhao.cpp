#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000001];
int bs(int x,int left,int right)
{
    if(left>right)
    {
        return -1;
    }
    int mid =(left+right)/2;
    if(x==a[mid])
    {
        int temp=bs(x,left,mid-1);
        if(temp>=0) return temp;
        else return mid;
    }
    if(x>a[mid])
    {
        return bs(x,mid+1,right);
    }
    else
    {
        return bs(x,left,mid-1);
    }
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		int place=bs(temp,1,n);
		cout<<place<<" ";
	}
	return 0;
}
