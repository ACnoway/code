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
int n,m,ans;
int a[20][20];
int v[20];
bool check(){
    bool flag=1;
    for(int i=1;i<=n;++i){
        if(v[i]==0){
            flag=0;
            break;
        }
    }
    return flag;
}
void dfs(int x){
    if(x>m) return;
    if(check()) ans++;
    dfs(x+1);
    for(int i=1;i<=a[x][0];++i) v[a[x][i]]++;
    dfs(x+1);
    for(int i=1;i<=a[x][0];++i) v[a[x][i]]--;
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i){
        a[i][0]=read();
        for(int j=1;j<=a[i][0];++j) a[i][j]=read();
    }
    dfs(1);
    write(ans);
    return 0;
}