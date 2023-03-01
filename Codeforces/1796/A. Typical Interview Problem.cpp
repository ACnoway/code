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
int t,k;
string s,ans="FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFB";
int main()
{
    cin>>t;
    while(t--){
        cin>>k>>s;
        if(ans.find(s)!=string::npos){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}