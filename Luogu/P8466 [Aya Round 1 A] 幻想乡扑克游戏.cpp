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
int t;
string s;
int main()
{
    cin>>t;
    bool flag;
    while(t--){
        flag=0;
        cin>>s;
        if(s[0]=='D'&&s[1]=='X'){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=0;i<s.size()-3;++i){
            if(s[i]==s[i+3]){
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}