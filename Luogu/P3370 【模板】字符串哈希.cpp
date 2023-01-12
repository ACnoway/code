#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int P=131;
typedef unsigned long long ull;
ull hs[10004];
int n,ans;
char s[10004][1003];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i]+1;
        for(int j=1;j<=strlen(s[i]+1);++j){
            hs[i]=hs[i]*P+s[i][j];
        }
    }
    sort(hs+1,hs+n+1);
    for(int i=1;i<=n;++i){
        if(hs[i]!=hs[i-1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}