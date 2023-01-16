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
int n,l;
char s[5003];
int main()
{
    cin>>n>>s+1;
    for(int i=1;i<n;++i){
        l=1;
        for(;l+i<=n;++l){
            if(s[l]==s[l+i]) break;
        }
        cout<<l-1<<endl;
    }
    return 0;
}