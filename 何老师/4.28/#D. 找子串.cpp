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
int T;
string s,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s>>t;
        int p=0;
        while((p=s.find(t))!=-1){
            s.erase(s.begin()+p,s.begin()+p+t.size());
        }
        cout<<s<<endl;
    }
    return 0;
}