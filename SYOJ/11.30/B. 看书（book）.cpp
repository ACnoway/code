#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=100005,M=500005;
int n,m,k;
int a[M],t[N];
bool has[N];
int main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=k;++i){
        a[i]=read();
        ++t[a[i]];
    }
    int cnt=0,ans=0;
    for(int i=1;i<=k;++i){
        --t[a[i]];
        if(has[a[i]]) continue;
        ++cnt;
        ++ans;
        has[a[i]]=1;
        if(cnt>=m){
            int mi=114514,p=0;
            for(int j=1;j<=i;++j){
                if(mi>t[a[j]]){
                    mi=t[a[j]];
                    p=j;
                }
            }
            has[a[p]]=0;
            --cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}
