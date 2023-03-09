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
int t,n,x,ukp,kp,ans;
int main()
{
    t=read();
    while(t--){
        n=read();
        ukp=kp=ans=0;
        for(int i=1;i<=n;++i){
            x=read();
            if(x==1){
                debug(kp);
                if(((kp+1)>>1)+ukp>=ans) ans++;
                ukp++;
            }
            else{
                kp+=ukp;
                ukp=0;
            }
            debug(ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}