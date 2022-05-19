#include <iostream>
#include <cstdio>
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
int a[1003][1003];
int n,m;
int main()
{
    n=read();
    m=read();
    for(int i=0;i<m;++i){
        int x1=read(),y1=read(),x2=read(),y2=read();
        a[x1][y1]++; a[x2+1][y2+1]++;
        a[x2+1][y1]--; a[x1][y2+1]--;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            write(a[i][j]);putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}