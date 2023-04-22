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
int n;
string s;
int main()
{
    cin>>n>>s;
    int cnt=0,ans=0;
    for(int i=0;i<n-1;++i){
        if(s[i]=='o'&&s[i+1]=='-'){
            cnt++;
            ans=max(cnt,ans);
            cnt=0;
        }
        else if(s[i]=='o') cnt++;
    }
    if(s[n-1]=='o') cnt++,ans=max(ans,cnt);
    if(ans==0||ans==n) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}