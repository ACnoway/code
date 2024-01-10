#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int read(){
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
const int N=300005;
int n,l,r;
int a[N],b[N],v[N];
typedef long long ll;
ll ans;
inline int lb(int x){return x&-x;}
void upd(int x){
    for(;x<=n;x+=lb(x)) ++v[x];
}
inline int que(int x){
    int sum=0;
    for(;x;x-=lb(x)) sum+=v[x];
    return sum;
}
bool cmp(int x,int y){return a[x]>a[y];}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),b[i]=i;
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;){
        int j=i;
        for(;j<=n;++j){
            int tmp=que(b[j]);
            ans+=min(tmp,i-1-tmp);
            if(a[b[j+1]]!=a[b[j]]) break;
        }
        for(;i<=j;++i) upd(b[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
