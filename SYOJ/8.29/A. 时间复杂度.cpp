#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=200,inf=INT_MAX>>1;
int n;
int p[N],bl[N],wc[N][N];
double sum[N];
typedef pair<int,int> pii;
pii a[N];
double m[N][N];
inline double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
inline int find(int x){
	while(p[x]!=x) x=p[x]=p[p[x]];
	return p[x];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(getchar()-'0') m[i][j]=dis((double)a[i].first,(double)a[i].second,(double)a[j].first,(double)a[j].second);
			else m[i][j]=inf;
		}
		getchar();
	}
	for(int i=1;i<=n;++i){for(int j=1;j<=n;++j) cout<<m[i][j]<<' '; cout<<endl;}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i) bl[i]=i,wc[i][1]=i,wc[i][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(m[i][j]!=inf){
				if(bl[j]!=bl[i]){
					bl[j]=bl[i];
					wc[bl[i]][++wc[bl[i]][0]]=j;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=wc[i][0];++j){
			for(int k=j+1;k<=wc[i][0];++k){
				sum[i]=max(sum[i],m[j][k]);
			}
		}
	}
	int ans=inf;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(bl[i]!=bl[j]){
				ans=min(ans,)
			}
		}
	}
	return 0;
}
