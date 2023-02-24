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
const int maxn=5003;
int n,now,ans,tmp;
int a[maxn],cnt[maxn];
int b[maxn][30],t[maxn][30];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        /*tmp=a[i];
        while(tmp){
            b[i][cnt[i]++]=tmp&1;
            tmp>>=1;
        }*/
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if((a[i]^a[j]^a[n-i+1]^a[n-j+1])==0) ans++;
        }
    }
    /*
    for(int i=1;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                for(int o=k+1;o<=n;++o){
                    if((a[i]^a[j]^a[k]^a[o])==0) ans++;
                }
            }
        }
    }*/
    write(ans);
    putchar('\n');
    return 0;
}