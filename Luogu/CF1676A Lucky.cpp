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
int t,a,b;
string s;
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        a=b=0;
        for(int i=0;i<3;++i){
            a+=s[i]-'0';
            b+=s[i+3]-'0';
        }
        if(a==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}