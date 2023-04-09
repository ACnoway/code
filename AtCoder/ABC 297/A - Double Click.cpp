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
int n,d,t;
int a[102];
int main()
{
    n=read();
    d=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(i>1){
            if(a[i]-a[i-1]<=d){
                cout<<a[i]<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}