#include <cstdio>
#include <cmath>
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
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
signed main()
{
    int x,y;
    x=read();y=read();
    long long all=x*y;
    int ans=0,flag=0;
    for(int i=x;i<=sqrt(all);i+=x){
        if(all%i==0&&gcd(i,all/i)==x){
            ans++;
            if(i*i==all) flag=1;
        }
    }
    write(ans*2-flag);
    return 0;
}
