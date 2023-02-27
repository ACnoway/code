// LUOGU_RID: 103167393
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int n,m,pre[N],suf[N];
char a[N][15];
signed main(){
	scanf("%d %d",&n,&m);
	mem(pre,0x3f);mem(suf,0x3f);
	pre[1]=0;suf[n]=0;
	for(int i=1;i<=n;i++){
		scanf(" %s",a[i]+1);
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='1') suf[i]=min(suf[i],suf[i+j]+1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='1') pre[i+j]=min(pre[i+j],pre[i]+1);
		}
	}
	for(int i=2;i<n;i++){
		int res=inf;
		for(int j=1;j<m&&i-j;j++){
			for(int k=j+1;k<=m;k++){
				if(a[i-j][k]=='1'){
					res=min(res,pre[i-j]+suf[i-j+k]);
				}
			}
		}
		printf("%d ",res==inf?-1:(res+1));
	}
} 
