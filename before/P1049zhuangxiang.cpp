#include<iostream>
#include<cstdio>
using namespace std;
int f[31][20001];
int main()
{
	int v,n,nv[31]={0};
	cin>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>nv[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			f[i][j]=f[i-1][j];
			if(j>=nv[i]&&f[i][j]<(f[i-1][j-nv[i]]+nv[i])){
				f[i][j]=f[i-1][j-nv[i]]+nv[i];
			}
		}
	}
	cout<<v-f[n][v];
	return 0;
}
