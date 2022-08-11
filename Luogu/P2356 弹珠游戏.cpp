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
int h[1003],l[1003];
int a[10004][2];
int n,cnt;
int main()
{
    cin>>n;
    int x;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>x;
            if(x){
                h[i]+=x;
                l[j]+=x;
            }
            else a[++cnt][0]=i,a[cnt][1]=j;
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;++i){
        ans=max(ans,h[a[i][0]]+l[a[i][1]]);
    }
    cout<<ans<<endl;
    return 0;
}