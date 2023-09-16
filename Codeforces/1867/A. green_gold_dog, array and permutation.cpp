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
const int N=40004;
int T,n;
typedef pair<int,int> pii;
pii a[N];
int b[N];
bool cmp(pii a,pii b){
    return a.first>b.first;
}
int main()
{
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=i;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;++i) b[a[i].second]=i;
        for(int i=1;i<=n;++i) printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}