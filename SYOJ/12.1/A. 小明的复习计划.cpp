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
const int N=100005,M=32;
int n,m;
int a[N],cnt[N][M],b[M];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        int tmp=0,x=a[i];
        while(x){
            ++tmp;
            cnt[i][tmp]=(x&1);
            x>>=1;
        }
        for(int j=m;j;--j) cnt[i][j]+=cnt[i-1][j];
    }
    int ans=0;
    for(int l=1;l<=n;++l){
        for(int r=l;r<=n;++r){
            for(int i=1;i<=m;++i) b[i]=cnt[r][i]-cnt[l-1][i];
            bool flag=1;
            for(int i=2;i<=m;++i)
                if(b[i]!=b[i-1]){
                    flag=0;
                    break;
                }
            if(flag) ans=max(ans,r-l+1);
        }
    }
    printf("%d\n",ans);
    return 0;
}
