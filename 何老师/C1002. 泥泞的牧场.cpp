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
int n,m;
char a[60][60];
bool v[60][60],fi[60][60];
int dfs(int x,int y,int way,int cnt){
    bool flag=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            if(a[i][j]=='*'&&fi[i][j]==0){
                flag=0;
                break;
            }
        if(!flag) break;
    }
    if(flag) return cnt;
}
int main()
{
    freopen("cover.in","r",stdin);
    freopen("cover.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    /*if(n<=5&&m<=5){
        write(min(dfs(1,1,0,0),dfs(1,1,1,0)));
        putchar('\n');
        return 0;
    }*/
    int cnts=0,cnth=0,ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]=='.') continue;
            cnts=cnth=0;
            for(int k=j-1;a[i][k]=='*';--k) cnth+=(!v[i][k]);
            for(int k=j+1;a[i][k]=='*';++k) cnth+=(!v[i][k]);
            for(int k=i-1;a[k][j]=='*';--k) cnts+=(!v[k][j]);
            for(int k=i+1;a[k][j]=='*';++k) cnts+=(!v[k][j]);
            if(cnth==0&&cnts==0) continue;
            ans++;
            if(cnth>cnts){
                for(int k=j-1;a[i][k]=='*';--k) v[i][k]=1;
                for(int k=j+1;a[i][k]=='*';++k) v[i][k]=1;
            }
            else{
                for(int k=i-1;a[k][j]=='*';--k) v[k][j]=1;
                for(int k=i+1;a[k][j]=='*';++k) v[k][j]=1;
            }
        }
    }
    write(ans);
    putchar('\n');
    fclose(stdin);
    fclose(stdout);
    return 0;
}