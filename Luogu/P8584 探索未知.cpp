#include <iostream>
#include <cstdio>
#include <algorithm>
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
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
struct fs{
    int fz,fm;
    fs(int _fz=0,int _fm=1):fz(_fz),fm(_fm){}
    void operator=(const fs &x){
        fz=x.fz;
        fm=x.fm;
        if(fz==0){
            fm=0;
            return;
        }
        int d=gcd(abs(fz),abs(fm));
        fz/=d;
        fm/=d;
    }
};
//分加分
fs operator+(const fs &a,const fs &b){
    return fs(a.fz*b.fm+b.fz*a.fm,a.fm*b.fm);
}
//分加数
fs operator+(const fs &a,const int &b){
    return fs(a.fz+b*a.fm,a.fm);
}
//分减分
fs operator-(const fs &a,const fs &b){
    return fs(a.fz*b.fm-b.fz*a.fm,a.fm*b.fm);
}
//分减数
fs operator-(const fs &a,const int &b){
    return fs(a.fz-b*a.fm,a.fm);
}
//分乘分
fs operator*(const fs &a,const fs &b){
    return fs(a.fz*b.fz,a.fm*b.fm);
}
//分乘数
fs operator*(const fs &a,const int &b){
    return fs(a.fz*b,a.fm);
}
//分除分
fs operator/(const fs &a,const fs &b){
    return fs(a.fz*b.fm,a.fm*b.fz);
}
//分除数
fs operator/(const fs &a,const int &b){
    return fs(a.fz,a.fm*b);
}
void operator+=(fs &a,const fs &b){
    a=a+b;
}
void operator+=(fs &a,const int &b){
    a=a+b;
}
void operator-=(fs &a,const fs &b){
    a=a-b;
}
void operator-=(fs &a,const int &b){
    a=a-b;
}
void operator*=(fs &a,const fs &b){
    a=a*b;
}
void operator*=(fs &a,const int &b){
    a=a*b;
}
void operator/=(fs &a,const fs &b){
    a=a/b;
}
void operator/=(fs &a,const int &b){
    a=a/b;
}
fs a,b;
int n,op;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>b.fz>>b.fm>>op;
        if(op==1) a+=b;
        else a-=b;
    }
    if(a.fm==1) cout<<a.fz<<endl;
    else cout<<a.fz<<'/'<<a.fm<<endl;
    return 0;
}