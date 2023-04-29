#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
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
const int N=1000006;
int T,n,m,top;
int fa[N],fb[N];
char s[N],t[N],st[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s+1>>t+1;
        n=strlen(s+1);
        m=strlen(t+1);
        top=0;
        for(int i=0;i<=n;++i) fa[i]=fb[i]=0;
        for(int i=2,j=0;i<=m;++i){
            while(j&&t[i]!=t[j+1]) j=fa[j];
            if(t[i]==t[j+1]) ++j;
            fa[i]=j;
        }
        for(int i=1,j=0;i<=n;++i){
            st[++top]=s[i];
            while(j&&st[top]!=t[j+1]) j=fa[j];
            if(st[top]==t[j+1]) ++j;
            fb[top]=j;
            if(j==m){
                top-=m;
                j=fb[top];
            }
        }
        for(int i=1;i<=top;++i) putchar(st[i]);
        putchar('\n');
    }
    return 0;
}