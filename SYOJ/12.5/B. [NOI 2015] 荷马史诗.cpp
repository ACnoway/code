#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll read(){
    ll x=0,f=1;
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
struct node{
    ll w,h;
    node(ll _w=0,ll _h=0):w(_w),h(_h){}
    bool operator <(const node &a)const{return a.w==w?h>a.h:w>a.w;}
};
ll ans;
priority_queue<node> q;

int main()
{
    ll n,k;
    n=read();
    k=read();
    for(int i=1;i<=n;++i){
        ll ww=read();
        q.emplace(ww,1);
    }
    while((q.size()-1)%(k-1)) q.emplace(0,1);
    while(q.size()>=k){
        ll h=-1,w=0;
        for(int i=1;i<=k;++i){
            node t=q.top();q.pop();
            h=max(t.h,h);
            w+=t.w;
        }
        ans+=w;
        q.emplace(w,h+1);
    }
    printf("%lld\n%lld\n",ans,q.top().h-1);
    return 0;
}
