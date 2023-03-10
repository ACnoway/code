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
int t,a,b,c,tmp;
int main()
{
    t=read();
    int ans,aa,ab,ac;
    while(t--){
        a=read();
        b=read();
        c=read();
        ans=INT_MAX;
        //注意枚举的上界要到2*c，因为倍数有可能加到2倍
        for(int i=1;i<=(c<<1);++i){
            for(int j=i;j<=(c<<1);j+=i){
                for(int k=j;k<=(c<<1);k+=j){
                    tmp=abs(a-i)+abs(b-j)+abs(c-k);
                    if(tmp<ans){
                        ans=tmp;
                        aa=i;
                        ab=j;
                        ac=k;
                    }
                }
            }
        }
        printf("%d\n%d %d %d\n",ans,aa,ab,ac);
    }
    return 0;
}