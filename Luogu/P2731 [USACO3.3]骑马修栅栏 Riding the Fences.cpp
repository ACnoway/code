#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int g[2000][2000],du[2000],c[2000];
int n,x,y,ma=-1000001,mi=1000001,s,k;
int find(int x){
	for(int i=mi;i<=ma;i++){
	    if(g[x][i]){
	        g[x][i]--;
	        g[i][x]--;
            find(i);
	    }
    }
	k=k+1;
	c[k]=x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		g[x][y]++;
		g[y][x]++;
		du[x]++;
		du[y]++;
        mi=min(mi,min(x,y));
        ma=max(ma,max(x,y));
	}
    int i;
	for(i=mi;i<=ma;i++){
	    if(du[i]%2==1) break;
	}
	if(i==ma+1) find(mi);
    else find(i);
	for(i=k;i>=1;i--)
	    cout<<c[i]<<endl;
	return 0;
}