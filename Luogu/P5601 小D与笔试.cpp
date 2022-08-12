#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,q;
string sa,sb;
unordered_map<string,string> m;
int main()
{
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>sa>>sb;
        m[sa]=sb;
    }
    for(int i=0;i<q;++i){
        cin>>sa;
        for(int j=0;j<4;++j){
            cin>>sb;
            if(m[sa]==sb) cout<<char(j+'A')<<endl;
        }
    }
    return 0;
}