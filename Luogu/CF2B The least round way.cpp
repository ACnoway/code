#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
inline int read(){
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
int n,xling,t;
int f[N][N][3],cnt[N][N][3];
void print(int i,int j,int k){
    if(i==1&&j==1){
        putchar(k?'D':'R');
        return;
    }
    if(i==1) print(i,j-1,0);
    else if(j==1) print(i-1,j,1);
    else if(f[i][j][t]==f[i][j-1][t]+cnt[i][j][t])
        print(i,j-1,0);
    else print(i-1,j,1);
    if(i!=n||j!=n)
        putchar(k?'D':'R');
}
int main()
{
    n=read();
    int ans=0,tmp;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            tmp=read();
            if(!tmp){
                cnt[i][j][0]=cnt[i][j][1]=1;
                xling=i;
            }
            else{
                while(tmp%2==0){
                    tmp/=2;
                    cnt[i][j][0]++;
                }
                while(tmp%5==0){
                    tmp/=5;
                    cnt[i][j][1]++;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        f[0][i][0]=f[i][0][0]=f[0][i][1]=f[i][0][1]=INT_MAX>>1;
    f[1][1][0]=cnt[1][1][0];
    f[1][1][1]=cnt[1][1][1];
    for(int k=0;k<2;++k){
        for(int i=1;i<=n;++i){
            for(int j=(i==1?2:1);j<=n;++j){
                f[i][j][k]=min(f[i][j-1][k],f[i-1][j][k])+cnt[i][j][k];
            }
        }
    }
    ans=min(f[n][n][0],f[n][n][1]);
    if(xling&&ans>1){
        printf("1\n");
        for(int i=1;i<xling;++i) putchar('D');
        for(int i=1;i<n;++i) putchar('R');
        for(int i=xling;i<n;++i) putchar('D');
    }
    else{
        printf("%d\n",ans);
        t=f[n][n][0]>=f[n][n][1];
        print(n,n,0);
    }
    return 0;
}