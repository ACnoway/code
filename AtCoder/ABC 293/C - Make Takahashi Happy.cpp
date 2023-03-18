#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
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
const int N=20,M=20;
int n,m;
int a[N][M];
int p[N<<1];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) a[i][j]=read();
    }
    int ans=0,l=n+m-2;
    fill(p+1,p+m,0);
    fill(p+m,p+l+1,1);
    do{
        int x=1,y=1;
        set<int> q;
        q.insert(a[x][y]);
        for(int i=1;i<=l;++i){
            if(p[i]) ++x;
            else ++y;
            q.insert(a[1][1]);
        }
        if(q.size()==l+1) ans++;
    }while(next_permutation(p+1,p+l+1));
    printf("%d\n",ans);
    return 0;
}