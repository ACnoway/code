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
const int N=30;
string a,b;
int vis[N];
int main()
{
    cin>>a>>b;
    for(int i=0;i<N;++i) vis[i]=-1;
    for(int i=0;i<a.size();++i) if(vis[a[i]-'A']==-1) vis[a[i]-'A']=i;
    int aa=10000,bb=0;
    for(int i=0;i<b.size();++i){
        if(vis[b[i]-'A']!=-1&&vis[b[i]-'A']<aa){
            aa=vis[b[i]-'A'];
            bb=i;
        }
    }
    for(int i=0;i<b.size();++i){
        for(int j=0;j<a.size();++j){
            if(i!=bb&&j!=aa) putchar('.');
            else if(i!=bb) putchar(b[i]);
            else putchar(a[j]);
        }
        putchar('\n');
    }
    return 0;
}