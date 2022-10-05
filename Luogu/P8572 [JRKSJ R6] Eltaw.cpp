#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
inline void write(long long x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,k,q,x;
vector<vector<long long> > a;
int in[500005][2];
long long b[500005];
int main()
{
    n=read();
    k=read();
    q=read();
    a.resize(k);
    for(int i=0;i<k;++i){
        a[i].resize(n+1);
        a[i][0]=0;
        for(int j=1;j<=n;++j){
            x=read();
            a[i][j]=x+a[i][j-1];
            b[j]=max(b[j],a[i][j]);
        }
    }
    for(int i=0;i<q;++i){
        cin>>in[i][0]>>in[i][1];
    }
    long long ans;
    for(int i=0;i<q;++i){
        if(in[i][0]==1){
            write(b[in[i][1]]);
            putchar('\n');
            continue;
        }
        ans=0;
        for(int j=0;j<k;++j) ans=max(ans,a[j][in[i][1]]-a[j][in[i][0]-1]);
        write(ans);
        putchar('\n');
    }
    return 0;
}