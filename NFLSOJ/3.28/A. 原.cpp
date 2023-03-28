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
int T,n,m,b,w;
int main()
{
    freopen("nsdd.in","r",stdin);
    freopen("nsdd.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        m=read();
        b=read();
        w=read();
        int cha;
        if(b==w){
            for(int i=1;i<=n<<2;++i){
                for(int j=1;j<=m<<2;++j){
                    if(!w&&!b){
                        putchar('.');
                        continue;
                    }
                    if((i+j)&1){
                        if(!w){putchar('.');continue;}
                        putchar('W');
                        --w;
                    }
                    else{
                        if(!b){putchar('.');continue;}
                        putchar('B');
                        --b;
                    }
                }
                putchar('\n');
            }
        }
        else if(w<=(b<<1)){
            cha=w-b;
            w=b;
            for(int i=1;i<=n<<2;++i){
                for(int j=1;j<=m<<2;++j){
                    if(!cha&&!w&&!b){
                        putchar('.');
                        continue;
                    }
                    if(!cha){
                        if((i+j)&1&&w) putchar('W'),--w;
                        else if(b) putchar('B'),--b;
                        else putchar('.');
                        continue;
                    }
                    if(i&1){
                        if((j&1)&&b) putchar('B'),--b;
                        else if(w) putchar('W'),--w;
                        else putchar('.');
                    }
                    else{
                        if((j&1)&&cha) putchar('W'),--cha;
                        else putchar('.');
                    }
                }
                putchar('\n');
            }
        }
        else{
            cha=w-b;
            w=b;
            for(int i=1;i<=n<<2;++i){
                for(int j=1;j<=m<<2;++j){
                    if(!cha&&!w&&!b){
                        putchar('.');
                        continue;
                    }
                    if(!cha){
                        if((i+j)&1&&w) putchar('W'),--w;
                        else if(b) putchar('B'),--b;
                        else putchar('.');
                        continue;
                    }
                    if(!(i&1)){
                        if((j&1)&&b) putchar('B'),--b;
                        else if(w) putchar('W'),--w;
                        else putchar('.');
                    }
                    else{
                        if((j&1)&&cha) putchar('W'),--cha;
                        else putchar('.');
                    }
                }
                putchar('\n');
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}