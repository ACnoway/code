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
        /*if(a==x.a){
            if(b==x.b) return c<x.c;
            return b<x.b;
        }
        if(b==x.b) return c<x.c;
        return a<x.a;*/
        return a+b+c<x.a+x.b+x.c;
    }
}t[200005];
int an[1000006][2];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>t[i].a>>t[i].b>>t[i].c,t[i].p=i,t[i].cnt=0;
    //sort(t+1,t+n+1);
    int ans=0,cc=0,temp=1844674407370955161;
    for(int i=1;i<=n;++i){
        an[++cc][0]=i;
        temp=1844674407370955161;
        for(int j=i+1;j<=n;++j){
            if(i==j) continue;
            if((t[j].a*(t[j].cnt+1)*(t[j].cnt+1)+t[j].b*(t[j].cnt+1)+t[j].c)<temp){
                temp=(t[j].a*(t[j].cnt+1)*(t[j].cnt+1)+t[j].b*(t[j].cnt+1)+t[j].c);
                an[cc][1]=j;
            }
        }
        t[an[cc][0]].cnt++;
        t[an[cc][1]].cnt++;
        ans+=(t[i].a*t[i].cnt*t[i].cnt+t[i].b*t[i].cnt+t[i].c);
        ans+=(t[an[cc][1]].a*t[an[cc][1]].cnt*t[an[cc][1]].cnt+t[an[cc][1]].b*t[an[cc][1]].cnt+t[an[cc][1]].c);
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;++i){
        cout<<t[an[i][0]].p<<' '<<t[an[i][1]].p<<endl;
    }
    return 0;
}