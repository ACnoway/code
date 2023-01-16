#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int maxn=10000007;
int n,k,cnt,ans=-maxn;
int a[maxn],t[maxn];
struct node{
    int v,p;
}fa[maxn],fb[maxn];
int get(int x){
    int l=fa[x].p,r=fb[x].p;
    int cc=t[r]-t[l-1];
    return a[r]-a[l-1]+(cc>k?k-cc+k:cc);
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<=n;++i){
        fa[i].p=fb[i].p=i;
        fa[i].v=maxn;
        fb[i].v=-maxn;
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
        t[i]=t[i-1];
        if(a[i]==0) cnt++,t[i]++;
        a[i]+=a[i-1];
        fa[i].v=fb[i].v=a[i];
        if(fa[i].v>fa[i-1].v){
            fa[i].v=fa[i-1].v;
            fa[i].p=fa[i-1].p;
        }
    }
    for(int i=n;i;--i){
        if(fb[i].v<fb[i+1].v){
            fb[i].v=fb[i+1].v;
            fb[i].p=fb[i+1].p;
        }
    }
    cout<<"v=";
    for(int i=1;i<=n;++i) cout<<fa[i].v<<' ';
    cout<<endl<<"p=";
    for(int i=1;i<=n;++i) cout<<fa[i].p<<' ';
    cout<<endl;
    cout<<"v=";
    for(int i=1;i<=n;++i) cout<<fb[i].v<<' ';
    cout<<endl<<"p=";
    for(int i=1;i<=n;++i) cout<<fb[i].p<<' ';
    cout<<endl;
    for(int i=1;i<=n;++i){
        ans=max(ans,get(i));
    }
    cout<<ans<<endl;
    return 0;
}