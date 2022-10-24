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
int n,d;
string s,ans;
int t[11];
bool v[100005];
int main()
{
    while(1){
        for(int i=0;i<10;++i) t[i]=0;
        cin>>n>>d;
        if(!n&&!d) break;
        cin>>s;
        while(d){
            ans="";
            for(int i=0;i<s.size();++i) v[i]=0;
            if(s[0]>s[1]) v[0]=1;
            if(s[s.size()-1]>s[s.size()-2]) v[s.size()-1]=1;
            for(int i=1;(i+1)<s.size();++i){
                if(s[i]>s[i-1]&&s[i]>s[i+1]) v[i]=1;
            }
            int i;
            for(i=0;i<s.size()&&d;++i){
                if(v[i]) ans+=s[i];
                else d--;
            }
            for(;i<s.size();++i) ans+=s[i];
            s=ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}