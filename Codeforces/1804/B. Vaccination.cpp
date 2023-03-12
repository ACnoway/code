#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
int t,n,k,d,w;
int a[200005];
signed main()
{
    t=read();
    while(t--){
        n=read();
        k=read();
        d=read();
        w=read();
        int ans=0,now=-1,cnt=0;
        for(int i=1;i<=n;++i){
            a[i]=read();
            if(a[i]>now||cnt==k){
                ans++;
                now=a[i]+w+d;
                cnt=1;
            }
            else cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}