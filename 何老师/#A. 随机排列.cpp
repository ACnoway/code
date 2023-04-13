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
int n;
int a[N],b[N],c[N];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    n=read();
    for(int i=0;i<n;++i) a[i]=read();
    // sort(a+1,a+n+1,cmp);
    for(int i=0;i<n;++i) b[i]=read();
    // sort(b+1,b+n+1,cmp);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int p=(i+j)%n;
            c[p]=max(c[p],a[i]+b[j]);
        }
    }
    for(int i=0;i<n;++i) printf("%d ",c[i]);
    putchar('\n');
    return 0;
}