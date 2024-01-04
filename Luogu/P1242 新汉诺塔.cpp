#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int read(){
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
const int N=25;
int n,ans,m,x;
int a[N],b[N];
string ch="0ABC";
void dfs(int x,int y){
    if(a[x]==y) return;
    for(int i=x-1;i>=1;--i) dfs(i,6-(a[x]+y));
    printf("move %d from %c to %c\n",x,ch[a[x]],ch[y]);
    a[x]=y;
    ++ans;
}
int main()
{
    n=read();
    for(int i=1;i<=3;++i){
        x=read();
        for(int j=1;j<=x;++j)
            a[read()]=i;
    }
    for(int i=1;i<=3;++i){
        x=read();
        for(int j=1;j<=x;++j)
            b[read()]=i;
    }
    for(int i=n;i>=1;i--) dfs(i,b[i]);
    printf("%d\n",ans);
    return 0;
}
