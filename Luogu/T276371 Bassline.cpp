#include<iostream>
#include<cstdio>
using namespace std;
int n,last,l,r,nr;
int a[300005],is[300005];
long long ans;
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
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        l=read();r=read();
        nr=max(nr,r);
        if(!is[l]) is[l]=1;
        is[r]=2;
        a[l]+=1;
        a[r+1]-=1;
    }
    for(int i=1;i<=nr;++i) a[i]+=a[i-1];
    int d;
    for(int i=1;i<=nr;++i){
        if(is[i]){
            d=(a[i]!=a[i-1]);
            ans=max(ans,(long long)a[i-d]*(i-d-last));
            last=i+is[i]-1;
        }
    }
    write(ans);
    return 0;
}