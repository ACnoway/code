#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m;
int a[200005],b[200005],c[200005];
struct node{
    int a,b,c,p,cnt;
    bool operator <(const node &x) const{
        if(a==x.a){
            if(b==x.b) return c<x.c;
            return b<x.b;
        }
        if(b==x.b) return c<x.c;
        return a<x.a;
    }
}t[200005];
int an[1000006][2];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>t[i].a>>t[i].b>>t[i].c,t[i].p=i,t[i].cnt=0;
    sort(t+1,t+n+1);
    int ans=0,cc=0;
    for(int i=1;i<=m-n+1;++i){
        ++cc;
        an[cc][0]=1;
        an[cc][1]=2;
        t[1].cnt++;
        t[2].cnt++;
        ans+=(t[1].a*t[1].cnt*t[1].cnt+t[1].b*t[1].cnt+t[1].c);
        ans+=(t[2].a*t[2].cnt*t[2].cnt+t[2].b*t[2].cnt+t[2].c);
    }
    int temp=0x7ffffff;
    for(int i=1;i<=n;++i){
        ++cc;
        temp=0x7ffffff;
        for(int j=1;j<i;++j){
            if(i==j) continue;
            if((t[j].a*(t[j].cnt+1)*(t[j].cnt+1)+t[j].b*(t[j].cnt+1)+t[j].c)<temp){
                temp=(t[j].a*(t[j].cnt+1)*(t[j].cnt+1)+t[j].b*(t[j].cnt+1)+t[j].c);
                an[cc][0]=i;an[cc][1]=j;
            }
        }
        t[an[cc][0]].cnt++;
        t[an[cc][1]].cnt++;
        ans+=(t[an[cc][0]].a*t[an[cc][0]].cnt*t[an[cc][0]].cnt+t[an[cc][0]].b*t[an[cc][0]].cnt+t[an[cc][0]].c);
        ans+=(t[an[cc][1]].a*t[an[cc][1]].cnt*t[an[cc][1]].cnt+t[an[cc][1]].b*t[an[cc][1]].cnt+t[an[cc][1]].c);
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;++i){
        cout<<t[an[i][0]].p<<' '<<t[an[i][1]].p<<endl;
    }
    return 0;
}