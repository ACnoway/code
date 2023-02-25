#include<cstdio>
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
int p,dif,x,y;
bool cnt[2003];
int main()
{
    p=read();
    bool flag;
    for(int i=0;i<p;++i){
        for(int j=0;j<=p;++j) cnt[j]=0;
        dif=0;
        flag=0;
        for(int j=0;j<p;++j){
            x=read();y=read();
            if(x!=y) flag=1;
            if(!cnt[x]) dif++,cnt[x]=1;
        }
        if(flag) write(dif);
        else putchar('0');
        putchar(' ');
    }
    return 0;
}