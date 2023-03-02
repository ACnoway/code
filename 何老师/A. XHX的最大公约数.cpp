#include<iostream>
#include<cmath>
#include<cstring>
#define int long long
using namespace std;
const int mod=1000000007;
int cnt,primes[10000007];
bool vis[100000002];
int zuhe(int m,int n){
    int tmp=1;
    for(int i=m+1;i<=n;++i){
        tmp=(tmp*i)%mod;
    }
    for(int i=2;i<=n-m;++i) tmp/=i;
    return tmp%mod;
}
signed main()
{
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=2;i<=m;i++){
        if(!vis[i]) primes[++cnt]=i;
        for(int j=1;j<=cnt&&i*primes[j]<=n;++j){
            vis[i*primes[j]]=1;
            if(i%primes[j]==0) break;
        }
    }
    cout<<zuhe(n,sum);
    return 0;
}