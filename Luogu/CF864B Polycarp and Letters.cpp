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
const int N=202;
int n;
string s;
bool vis[30];
int main()
{
    cin>>n>>s;
    int ans=0,cnt=0;
    for(int i=0;i<s.size();++i){
        if(s[i]>='a'&&s[i]<='z'&&!vis[s[i]-'a']) ++cnt,vis[s[i]-'a']=1;
        else if(s[i]<'a'|s[i]>'z'){
            ans=max(ans,cnt);
            cnt=0;
            for(int j=0;j<26;++j) vis[j]=0;
        }
    }
    ans=max(ans,cnt);
    printf("%d\n",ans);
    return 0;
}