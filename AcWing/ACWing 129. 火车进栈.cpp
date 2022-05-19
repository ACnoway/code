#include<iostream>
#include<cstdio>
using namespace std;
int read(){
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
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,t,cnt;
int st[25],a[25];
void print(){
    for(int i=1;i<=n;++i){
        write(a[i]);
    }
}
void dfs(int x){
    if(x>n) return;
    if(x==n){
        a[++cnt]=x;
        print();
        cnt--;
        return;
    }
    st[++t]=x;
    
}
int main()
{
    n=read();
    dfs(1);
    return 0;
}