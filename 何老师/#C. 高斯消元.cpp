#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
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
const int N=100005;
int n,m,k,siz;
int a[N],nxt[N],bef[N];
signed main()
{
    n=read();
    m=read();
    k=read();
    siz=n*m;
    bool flag=1;
    nxt[0]=1; bef[n+1]=n;
    for(int i=1;i<=n;++i){
        a[i]=read();
        nxt[i]=i+1;
        bef[i]=i-1;
        if(i>1&&a[i]!=a[i-1]) flag=0;
    }
    if(flag){
        cout<<(n*m)%k<<endl;
        return 0;
    }
    bool over=0;
    while(over&&siz>0){
        debug(siz);
        int cnt=0,st=nxt[0];
        for(int i=nxt[0];i<=n;i=nxt[i]){
            debug(i);
            if(a[i]==a[bef[i]]){
                ++cnt;
                if(cnt==k){
                    cnt=0;
                    over=0;
                    siz-=k;
                    bef[nxt[i]]=bef[st];
                    nxt[bef[st]]=nxt[i];
                }
            }
            else{
                cnt=1;
                st=i;
            }
        }
        cnt=1;
        int l=0,r=0;
        for(int i=nxt[nxt[0]];i<=n;i=nxt[i]){
            if(a[i]==a[bef[i]]) ++cnt;
            else{
                r=i;
                break;
            }
        }
        if(a[nxt[0]]==a[bef[n+1]]) ++cnt;
        for(int i=bef[n+1];i;i=bef[i]){
            if(a[i]==a[bef[i]]) ++cnt;
            else{
                l=bef[i];
                break;
            }
        }
        if(cnt>=k){
            cnt-=k;
            siz-=k;
            nxt[l]=n+1;
            bef[n+1]=l;
            for(int i=bef[r],j=0;i<=n&&j<=cnt;i=nxt[i],++j){
                l=nxt[i];
            }
            bef[l]=0;
            nxt[0]=l;
        }
    }
    flag=1;
    for(int i=nxt[nxt[0]];i<=n;i=nxt[i]){
        if(a[i]!=a[bef[i]]){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<siz*m%k<<endl;
    }
    else{
        cout<<siz<<endl;
    }
    return 0;
}