#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int ans;
int f[10004];
int main()
{
    /*
    f[1]=1;
    f[2]=2;
    f[3]=2;
    f[4]=2*2=4;
    */
    int n;
    n=read();
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;++i){
        if(i&1){
            f[i]=f[i-1];
            continue;
        }
        else{
            for(int j=1;j<=i/2;++j) f[i]+=f[j];
            f[i]++;
        }
    }
    write(f[n]);
    return 0;
}
