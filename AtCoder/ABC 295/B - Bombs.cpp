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
int n,m;
char s[30][30];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>s[i]+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i][j]>='0'&&s[i][j]<='9'){
                int now=s[i][j]-'0';
                for(int x=1;x<=n;++x){
                    for(int y=1;y<=m;++y){
                        if((s[x][y]=='.'||s[x][y]=='#')&&abs(x-i)+abs(y-j)<=now){
                            s[x][y]='.';
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i][j]=='.'||s[i][j]=='#') putchar(s[i][j]);
            else putchar('.');
        }
        putchar('\n');
    }
    return 0;
}