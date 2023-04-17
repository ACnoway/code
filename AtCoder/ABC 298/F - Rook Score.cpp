#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
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
const int N=200005;
int n;
int row[N],col[N],irow[N],icol[N];
struct node{
    int x,y,v;
}a[N];
map<int,int> hang,lie;
bool cmpr(int x,int y){
    if(row[x]==row[y]) return x<y;
    return row[x]>row[y];
}
bool cmpc(int x,int y){
    if(col[x]==col[y]) return x<y;
    return col[x]>col[y];
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i].x=read();
        if(!hang[a[i].x]) hang[a[i].x]=hang.size()+1;
        a[i].x=lie[a[i].x];
        
        a[i].y=read();
        if(!lie[a[i].y]) lie[a[i].y]=lie.size()+1;
        a[i].y=lie[a[i].y];
        
        a[i].v=read();
        row[a[i].x]+=a[i].v;
        col[a[i].y]+=a[i].v;
    }
    
    return 0;
}