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
inline void write(long long x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n;
int main()
{
    n=read();
    long long ans=0;
    int ab,cd;
    for(int i=1;i<n;++i){
        ab=cd=0;
        for(int j=1;j*j<=i;++j){
            if(i%j==0){
                ab++;
                if(j*j!=i) ab++;
            }
        }
        for(int j=1;j*j<=n-i;++j){
            if((n-i)%j==0){
                cd++;
                if(j*j!=n-i) cd++;
            }
        }
        ans+=ab*cd;
    }
    write(ans);
    putchar('\n');
    return 0;
}