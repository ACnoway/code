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
int n,m,ans,tmp;
int a[20];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i]=i;
    do{
        bool flag=1;
        for(int i=m+1;i<=n;++i){
            tmp=n+1;
            for(int j=i-m;j<i;++j){
                tmp=min(tmp,a[j]);
            }
            if(a[i]<=tmp){
                flag=0;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(a+1,a+n+1));
    printf("%d\n",ans);
    return 0;
}