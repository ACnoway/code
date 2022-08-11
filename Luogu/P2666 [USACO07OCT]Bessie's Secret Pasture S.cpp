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
int pf[10004];
bool is[10004];
int n,ans;
int main()
{
    cin>>n;
    for(int i=0;i*i<=n;++i) pf[i]=i*i,is[i*i]=true;
    for(int i=0;i*i<=n;++i){
        for(int j=0;j*j<=n;++j){
            if(pf[i]+pf[j]>n) break;
            for(int k=0;k*k<=n;++k){
                if(pf[i]+pf[k]>n||pf[j]+pf[k]>n) break;
                if(is[n-pf[i]-pf[j]-pf[k]]) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}