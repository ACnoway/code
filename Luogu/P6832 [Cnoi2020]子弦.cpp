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
int a[27];
string s;
int ans;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i) a[s[i]-'a']++;
    for(int i=0;i<26;++i){
        ans=max(ans,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}