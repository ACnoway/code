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
const int N=200005;
int n,cnt;
int a[N],b[N],aa[N],bb[N],c[N];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    n=read();
    for(int i=0;i<n;++i) a[i]=read(),aa[a[i]]=i;
    for(int i=0;i<n;++i) b[i]=read(),bb[b[i]]=i;
    for(int i=2*n-2;i>=0;--i){
        for(int j=i-n+1;j<n;++j){
            if(!c[(aa[i-j]+bb[j])%n]){
                ++cnt;
                c[(aa[i-j]+bb[j])%n]=i;
                if(cnt==n){
                    for(int k=0;k<n;++k){
                        printf("%d ",c[k]);
                    }
                    putchar('\n');
                    return 0;
                }
            }
        }
    }
    return 0;
}