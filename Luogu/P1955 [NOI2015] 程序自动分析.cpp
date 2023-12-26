#include<iostream>
#include<cstdio>
#include<unordered_map>
#define int long long
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
const int N=400005;
int t,n,cnt,c;
int p[N];
int a[N][2];
unordered_map<int,int> m;
int find(int x){
    while(x!=p[x]) x=p[x]=p[p[x]];
    return p[x];
}
signed main()
{
    t=read();
    int x,y,e;
    bool flag;
    while(t--){
        n=read();
        cnt=0;
        c=0;
        m.clear();
        for(int i=0;i<N;++i) p[i]=i;
        for(int i=0;i<n;++i){
            x=read();y=read();e=read();
            if(!m[x]) m[x]=++c;
            if(!m[y]) m[y]=++c;
            if(e) p[find(m[x])]=find(m[y]);
            else a[++cnt][0]=x,a[cnt][1]=y;
        }
        flag=true;
        for(int i=1;i<=cnt;++i){
            if(find(m[a[i][0]])==find(m[a[i][1]])){
                flag=false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
