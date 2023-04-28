#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int T,n,k;
int main()
{
    T=read();
    while(T--){
        n=read(); k=read();
        if(n>2&&!k){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag=0;
        int ans=-1;
        for(int i=0;i<=n;++i){
            int x=max(0,i-1),y=max(0,n-i-1);
            if((1+x)*x/2+(1+y)*y/2==k){
                flag=1;
                ans=i;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            for(int i=1;i<=ans;++i) cout<<1<<' ';
            for(int i=1;i<=n-ans;++i) cout<<-1<<' ';
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}