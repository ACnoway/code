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
int n,q,op,x,jiao=1,mei=1;
bool tong[500005];
int main()
{
    n=read();
    q=read();
    while(q--){
        op=read();
        if(op==1){
            jiao++;
        }
        else if(op==2){
            x=read();
            tong[x]=1;
            while(tong[mei]) mei++;
        }
        else{
            printf("%d\n",mei);
        }
    }
    return 0;
}