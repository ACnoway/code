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
int t,n,x,p;
signed main()
{
    t=read();
    while(t--){
        n=read();
        x=read();
        p=read();
        bool flag=0;
        for(int i=1;i<=min(p,n*2);++i){
            if((x+(1+i)*i/2)%n==0){
                cout<<"Yes"<<endl;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        cout<<"No"<<endl;
    }
    return 0;
}