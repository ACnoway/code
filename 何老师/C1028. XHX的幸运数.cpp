#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=100005;
int n,ans,cnt,now;
char s[maxn];
int top,st[maxn],cut[maxn];
int pre[maxn],nxt[maxn];
signed main()
{
    cin>>n;
    cin>>s+1;
    nxt[0]=1;
    for(int i=1;i<=n;++i){
        pre[i]=i-1;
        nxt[i]=i+1;
    }
    while(1){
        cnt=0;
        now=nxt[0];
        for(int i=1;now<=n;++i){
            if(nxt[now]<=n&&s[now]=='4'&&s[nxt[now]]=='7'){
                cnt++;
                ans+=i;
                nxt[pre[now]]=nxt[nxt[now]];
                pre[nxt[nxt[now]]]=pre[now];
            }
            now=nxt[now];
        }
        if(!cnt) break;
    }
    write(ans);
    putchar('\n');
    return 0;
}