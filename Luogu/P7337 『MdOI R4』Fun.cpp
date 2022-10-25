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
int n,m,x,op,cnt;
int a[102],b[102];
int main()
{
    cin>>n>>m>>op;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    for(int i=0;i<n;++i){
        if(a[i]&&b[i]) cnt++;
    }
    if(cnt>=m) cout<<n-cnt+m<<endl;
    else cout<<n<<endl;
    return 0;
}