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
const int N=1000006,mod=1e9+7;
int T,n,m;
int er[N];
string a,b,c,tmp;
signed main()
{
    freopen("zood.in","r",stdin);
    freopen("zood.out","w",stdout);
    T=read();
    er[2]=2;
    for(int i=3;i<N;++i) er[i]=(er[i-1]*(i-1))%mod;
    for(int i=1;i<10;++i) tmp+=i+'0';
    a=b=tmp;
    int lastn=0;
    while(T--){
        n=read(); m=read();
        a=b=tmp;
        if(m==2){
            printf("%d\n",er[n]);
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}