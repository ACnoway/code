#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
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
int T,n;
int a[200005],b[200005],t[200005];
int main()
{
    T=read();
    b[0]=-1;
    while(T--){
        n=read();
        for(int i=0;i<=n;++i) t[i]=0;
        for(int i=1;i<=n;++i){
            a[i]=read();
            if(a[i]<=n) t[a[i]]++;
        }
        int mex=0;
        for(int i=0;i<=n;++i){
            if(!t[i]){
                mex=i;
                break;
            }
        }
        if(mex>=n){
            cout<<"NO"<<endl;
            continue;
        }
        mex++;
        if(!t[mex]){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=0;i<=n;++i) t[i]=0;
        t[mex-1]=1;
        for(int i=1;i<=n&&a[i]!=mex;++i){
            if(a[i]<mex){
                ++t[a[i]];
            }
        }
        for(int i=n;i&&a[i]!=mex;--i){
            if(a[i]<mex){
                ++t[a[i]];
            }
        }
        for(int i=0;i<=n;++i){
            if(!t[i]){
                if(mex==i){
                    cout<<"YES"<<endl;
                    break;
                }
                else{
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}