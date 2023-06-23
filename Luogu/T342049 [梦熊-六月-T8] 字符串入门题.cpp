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
int n,k;
string s;
int cnt[200];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<=n-k;++i) ++cnt[s[i]];
    for(int i=n-k+1;i<n;++i){
        if(!cnt[s[i]]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<k<<endl;
    for(int i=0;i<=n-k;++i){
        putchar(s[i]);
    }
    putchar('\n');
    for(int i=n-k+1;i<n;++i){
        cout<<s[i]<<endl;
    }
    return 0;
}