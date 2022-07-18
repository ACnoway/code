#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int f[21][21][21];
int w(int a,int b,int c){
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) return w(20,20,20);
    if(a<b&&b<c){
        if(f[a][b][c-1]==0) f[a][b][c-1]=w(a,b,c-1);
        if(f[a][b-1][c-1]==0) f[a][b-1][c-1]=w(a,b-1,c-1);
        if(f[a][b-1][c]==0) f[a][b-1][c]=w(a,b-1,c);
        return f[a][b][c-1]+f[a][b-1][c-1]-f[a][b-1][c];
    }
    if(f[a][b][c]!=0) return f[a][b][c];
    f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return f[a][b][c];
}
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x+'0');
}
signed main()
{
    int a,b,c;
    a=read();b=read();c=read();
    while(!(a==-1&&b==-1&&c==-1)){
        int ans=w(a,b,c);
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,ans);
        a=read();b=read();c=read();
    }
    return 0;
}
