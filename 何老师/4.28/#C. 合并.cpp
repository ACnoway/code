#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
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
const int N=150005,inf=1000000009;
int n;
int a[N];
map<int,int> m;
vector<int> p;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),++m[a[i]];
    int mi;
    while(1){
        mi=inf;
        p.clear();
        for(int i=1;i<=n;++i){
            if(a[i]<mi&&m[a[i]]>1){
                mi=a[i];
                p.clear();
                p.push_back(i);
            }
            else if(a[i]==mi){
                p.push_back(i);
            }
        }
        if(p.size()<2) break;
        for(int i=0;i+1<p.size();i+=2){
            m[mi]-=2;
            a[p[i+1]]=2*mi;
            ++m[a[p[i+1]]];
            a[p[i]]=inf+1;
        }
    }
    p.clear();
    for(int i=1;i<=n;++i) if(a[i]!=inf+1) p.push_back(a[i]);
    printf("%d\n",p.size());
    for(int i:p) printf("%d ",i);
    return 0;
}