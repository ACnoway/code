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
string s;
long long ans;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i){
        ans=ans*26+(s[i]-'A'+1);
    }
    cout<<ans<<endl;
    return 0;
}