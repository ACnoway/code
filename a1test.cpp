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
int n,k,cnt,sum,ans;
bool isp[100000008];
int p[10000007];
int a[30];
bool v[30];
void shai(int nn){
    for(int i=2;i<=nn;++i) isp[i]=true;
    for(int i=2;i<=nn;++i){
        if(isp[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=nn;++j){
            isp[i*p[j]]=false;
            if(i%p[j]==0) break;
        }
    }
}
void dfs(int kk,int now){
    if(kk==k+1){
        if(isp[now]) ans++;
        return;
    }
    for(int i=0;i<n;++i){
        if(!v[i]){
            v[i]=1;
            dfs(kk+1,now+a[i]);
            v[i]=0;
        }
    }
    return;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    shai(sum);
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}