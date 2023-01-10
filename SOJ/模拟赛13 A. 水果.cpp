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
int n,m,x,y;
char a[100005],c;
int f[100005];
int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
void merge(int x,int y){
    f[find(x)]=find(y);
}
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
int main()
{
    n=read();m=read();
    cin>>a+1;
    for(int i=1;i<=n;++i) f[i]=i;
    for(int i=1;i<n;++i){
        x=read();y=read();
        if(a[x]==a[y]) merge(x,y);
    }
    for(int i=1;i<=m;++i){
        x=read();y=read();c=getchar();
        cout<<(find(x)^find(y)||a[find(x)]==c);
    }
    cout<<endl;
    return 0;
}