#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int now[21],up[21];
	int a,n,m,x,i;
	cin>>a>>n>>m>>x;
	now[1]=a; up[1]=a;
	now[2]=a;
	for(i=0;i<=m;i++){
		up[2]=i;
		for(int j=3;j<n;j++){
			up[j]=up[j-2]+up[j-1];
			now[j]=now[j-1]+up[j]-up[j-1];
		}
		if(now[n-1]==m) break;
	}
	cout<<now[x];
	return 0;
}
