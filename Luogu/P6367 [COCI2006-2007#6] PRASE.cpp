#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,ans;
map<string,int> m;
int main()
{
    cin>>n;
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        if(m[s]>i-m[s]) ans++;
        m[s]++;
    }
    cout<<ans<<endl;
    return 0;
}