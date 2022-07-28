#include<iostream>
#include<cmath>
using namespace std;
long long f[22][22];
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	n++;m++;x++;y++;f[0][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((abs(i-x)+abs(j-y)==3)&&(i!=x)&&(j!=y)||(i==x&&j==y));
			else f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	cout<<f[n][m];
	return 0;
}
