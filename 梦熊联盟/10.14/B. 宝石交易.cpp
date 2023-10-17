#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=1003;
int x,y,z,tot,ans,inf;
int a[5][10];
int val[10]={0,100,50,20,10,5,1},cnt[N],sum[N];
int f[10][N][N];
int main()
{
//	freopen("debt.in","r",stdin);
//	freopen("debt.out","w",stdout);
	x=read();
	y=read();
	z=read();
	if(x==y&&y==z){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=3;++i){
		for(int j=1;j<=6;++j){
			a[i][j]=read();
			sum[i]+=a[i][j]*val[j];
			tot+=a[i][j]*val[j];
			cnt[j]+=a[i][j];
		}
	}
	for(int i=0;i<10;++i)
		for(int j=0;j<N;++j)
			for(int k=0;k<N;++k) f[i][j][k]=127;
	f[0][sum[1]][sum[2]]=0;
	inf=ans=f[1][1][1];
	for(int i=1;i<=6;++i){
		for(int j=0;j<=tot;++j){
			for(int k=0;k+j<=tot;++k){
				if(f[i-1][j][k]!=inf){
					for(int x1=0;x1<=cnt[i];++x1){
						for(int x2=0;x1+x2<=cnt[i];++x2){
							int now1=j-(a[1][i]-x1)*val[i];
							int now2=k-(a[2][i]-x2)*val[i];
							int x3=cnt[i]-x1-x2;
							if(now1>=0&&now2>=0&&now1+now2<=tot){
								int w=abs(a[1][i]-x1)+abs(a[2][i]-x2)+abs(a[3][i]-x3);
								f[i][now1][now2]=min(f[i][now1][now2],f[i-1][j][k]+(w>>1));
							}
						}
					}
				}
			}
		}
	}
	int s1=sum[1]-x+z,s2=sum[2]-y+x,s3=sum[3]-z+y;
	for(int i=0;i<=6;++i){
		ans=min(ans,f[i][s1][s2]);
	}
	if(s1<0||s2<0||s3<0||ans==inf){
		printf("impossible");
	}
	else printf("%d\n",ans);
	return 0;
}
