#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=300005;
int u[N],v[N],w[N],d[N],p[N];
int n,s,t;
int main()
{
    cin>>n>>s>>t;
    unsigned long long ans=0;
    for(int i=1;i<n;++i){
        cin>>u[i]>>v[i]>>w[i];
        p[v[i]]=i;
    }
    for(int i=1;i<=n;++i){
        if(i==s||i==t) continue;
        int ws=w[p[i]]+w[p[s]],wt=w[p[i]]+w[p[t]];
        d[p[i]]=2;
        if(ws<wt){
            ans+=ws;
            d[p[s]]=1;
        }
        else{
            ans+=wt;
            d[p[t]]=1;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<n;++i) cout<<d[i];
    cout<<endl;
    return 0;
}