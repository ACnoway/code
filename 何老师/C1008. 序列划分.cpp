#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
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
const int maxn=500005;
int d,d1,n,f;
int a[maxn],b[maxn],t[maxn][2];
char s[maxn];
int main()
{
    cin>>s+1>>d;
    n=strlen(s+1);
    d1=1;
    while(d%2==0){
        d>>=1;
        d1<<=1;
    }
    while(d%5==0){
        d/=5;
        d1*=5;
    }
    for(int i=1;i<=n;++i){
        b[i]=s[i]-'0';
        a[i]=(a[i-1]*10+s[i]-'0')%d;
    }
    f=1;
    for(int i=n;i;--i){
        
    }
    return 0;
}