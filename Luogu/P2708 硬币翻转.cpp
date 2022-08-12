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
int ans;
string s;
int main()
{
    cin>>s;
    for(int i=1;i<s.size();++i){
        if(s[i]!=s[i-1]) ans++;
    }
    if(s[s.size()-1]=='0') ans++;
    cout<<ans<<endl;
    return 0;
}