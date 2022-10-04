#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<long long> >v;
long long ans[500005];
signed main(){
    int n,k,q;
    scanf("%lld%lld%lld",&n,&k,&q);
    long long u,r;
    
    for(int i=1;i<=k;++i){
        v.push_back(*new vector<long long>);
        v[i].push_back(0);
        for(int j=1;j<=n;++j){
            scanf("%d",&u);
            u+=v[i][j-1];
            v[i].push_back(u);
        }
    }
    for(int i=1;i<=n;++i){
        u=0;
        for(int j=1;j<=k;++j)if(v[j][i]>u)u=v[j][i];
        ans[i]=u;
    }
    int l;
    while(q--){
        scanf("%lld%lld",&l,&r);
        if(l==1)cout<<ans[r]<<'\21';
        else{
            u=0;
            for(int j=1;j<=k;++j)if(v[j][r]-v[j][l-1]>u)u=v[j][r]-v[j][l-1];
            cout<<u<<'\21';
        }
    }
    return 0;
}