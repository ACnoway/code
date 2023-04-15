#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
int t;
string s;
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        int ans=0;
        if(s=="_"){
            cout<<2<<endl;
            continue;
        }
        if(s[0]=='_') ++ans;
        if(s[s.size()-1]=='_') ++ans;
        if(s.size()==1) ++ans;
        for(int i=1;i<s.size();++i){
            if(s[i]==s[i-1]&&s[i]=='_') ++ans; 
        }
        cout<<ans<<endl;
    }
    return 0;
}