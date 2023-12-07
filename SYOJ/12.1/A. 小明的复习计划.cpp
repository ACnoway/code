#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#define int unsigned long long
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
const int N=200005,M=32,base=131;
map<int,int> mp;
int n,m,hsh,x,ans;
int cnt[N][M],b[M];
signed main()
{
    n=read();
    m=read();
    mp[0]=0;
    for(int i=1;i<=n;++i){
        x=read();
        for(int j=1;j<=m;++j){
            cnt[i][j]=cnt[i-1][j];
            if((x>>(j-1))&1) ++cnt[i][j];
        }
        for(int j=1;j<=m;++j) b[j]=cnt[i][j]-cnt[i][j-1];
        b[1]=cnt[i][1]-cnt[i][m];
        hsh=0;
        for(int j=1;j<=m;++j) hsh=base*hsh+b[j];
        if(mp.find(hsh)==mp.end()) mp[hsh]=i;
        else ans=max(ans,i-mp[hsh]);
    }
    printf("%Ld\n",ans);
    return 0;
}
