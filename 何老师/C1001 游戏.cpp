#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline long long read(){
    long long x=0,f=1;
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
long long t,x,y,k;
int main()
{
    t=read();
    while(t--){
        x=read();y=read();
        k=ceil(pow(x*y,1.0/3));
        if(k*k*k==x*y&&x%k==0&&y%k==0) printf("Yes");
        else printf("No");
        putchar('\n');
    }
    return 0;
}