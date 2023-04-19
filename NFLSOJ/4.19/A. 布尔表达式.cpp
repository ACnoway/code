#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
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
const int N=100005,mod=998244353;
int T,n,top;
int pos[N],st[N],f[N][2];
char s[N];
int calc(char op,int x,int y){
    if(op=='&') return x&y;
    if(op=='|') return x|y;
    if(op=='^') return x^y;
}
void dfs(int x){
    if(s[x]=='#'){
        f[x][0]=f[x][1]=(mod+1)/2;
        return;
    }
    dfs(x+1);
    dfs(pos[x]+1);
    f[x][0]=f[x][1]=0;
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            int tmp=calc(s[pos[x]],i,j);
            f[x][tmp]+=f[x+1][i]*f[pos[x]+1][j]%mod;
            f[x][tmp]%=mod;
        }
    }
}
signed main()
{
    freopen("boolexpr.in","r",stdin);
    freopen("boolexpr.out","w",stdout);
    cin>>T;
    while(T--){
        top=0;
        cin>>s+1;
        n=strlen(s+1);
        for(int i=0;i<n;++i){
            if(s[i]=='(') st[++top]=i;
            else if(s[i]==')') --top;
            else if(s[i]!='#') pos[st[top]]=i;
        }
        dfs(1);
        cout<<f[1][0]*f[1][0]%mod<<' '<<f[1][1]*f[1][1]%mod<<' ';
        cout<<f[1][0]*f[1][1]%mod<<' '<<f[1][1]*f[1][0]%mod<<'\n';
    }
    return 0;
}