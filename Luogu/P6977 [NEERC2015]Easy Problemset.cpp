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
int n,k,ans,p;
int a[11][11];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>p;
        for(int j=1;j<=p;++j) cin>>a[i][j];
        a[i][p+1]=-1;
        a[i][0]=p;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=a[i][0];++j) cout<<a[i][j]<<' ';
        cout<<endl;
    }
    p=1;
    while(k){
        if(a[p][a[p][0]]==-1){
            ans+=50;k--;
            p=(p+1)%(n+1)+1;
        }
        else{
            if(a[p][a[p][0]]>=ans){
                ans+=a[p][a[p][0]];
                a[p][0]++;
                k--;
                p=(p+1)%(n+1)+1;
            }
            else a[p][0]++,p=(p+1)%(n+1)+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}