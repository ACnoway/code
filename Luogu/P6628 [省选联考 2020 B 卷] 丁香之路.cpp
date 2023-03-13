#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
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
const int N=3003;
int n,m,s,sum;
int belong[N],du[N];
struct node{
    int u,v,w;
    node(int _u,int _v,int _w):
        u(_u),v(_v),w(_w){};
    bool operator <(const node b)const{
        return w<b.w;
    }
};
//* -----并查集
int p[N];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
inline void merge(int x,int y){
    p[find(x)]=find(y);
}
int main()
{
    n=read(); m=read(); s=read();
    for(int i=1;i<=n;++i) p[i]=i;
    for(int i=1;i<=m;++i){
        int x=read(),y=read();
        ++du[x]; ++du[y];
        sum+=abs(x-y);
        merge(x,y);
    }
    //准备缩点，存一下每个点的祖先
    for(int i=1;i<=n;++i) belong[i]=find(i);
    for(int i=1;i<=n;++i){
        //重置并查集
        for(int j=1;j<=n;++j) p[j]=j;
        //把起点和所有终点连边
        ++du[s]; ++du[i];
        //这里连边记得连它之前的祖先，因为要缩点求最小生成树
        merge(belong[s],belong[i]);
        ll ans=sum,pre=0;
        for(int j=1;j<=n;++j){
            //如果是奇数点就开始连边
            if(du[j]&1){
                if(pre){
                    //度数是奇数就往下连边，可证这样连边代价最小
                    ans+=j-pre;
                    for(int k=pre;k<j;++k){
                        merge(belong[k],belong[j]);
                    }
                    pre=0;
                }
                else pre=j;
            }
        }
        vector<node> e;
        for(int j=1;j<=n;++j){
            if(du[j]){
                if(pre&&find(belong[j])!=find(belong[pre])){
                    e.push_back(node(belong[j],belong[pre],abs(j-pre)));
                }
                pre=j;
            }
        }
        sort(e.begin(),e.end());
        //计算最小生成树的代价
        for(int j=0;j<e.size();++j){
            if(find(e[i].u)!=find(e[i].v)){
                merge(e[j].u,e[j].v);
                ans+=e[j].w*2;
            }
        }
        --du[s]; --du[i];
        printf("%lld\n",ans);
    }
    return 0;
}