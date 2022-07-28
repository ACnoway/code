#include <iostream>
#include <cstdio>
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
bool a[2000006]={1,1};
int b[2000006];
int n[500005];
int t,maxn,cnt;
void oula(){
    for(int i=2;i<=maxn;i++)
	{
		if (a[i]==0)	b[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*b[j]>maxn)break;
			a[i*b[j]]=1;
			if(i%b[j]==0)break;
		}	
	}
}
int main()
{
    t=read();
    for(int i=1;i<=t;++i){
        n[i]=read();
        maxn=max(maxn,n[i]);
    }
    oula();
    for(int i=1;i<=t;++i){
        if(n[i]==1){
            write(1);
            putchar('\n');
            continue;
        }
        for(int j=n[i];j>0;--j){
            if(a[j]==0){
                write(j);
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}