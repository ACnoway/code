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
int a,b,e,f,x,y;
int main()
{
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            char c=getchar();
            while(c!='.'&&c!='B'&&c!='R'&&c!='L') c=getchar();
            switch (c){
                case 'B':{
                    //cout<<i<<' '<<j<<endl;
                    a=i;
                    b=j;
                    break;
                }
                case 'R':{
                    //cout<<i<<' '<<j<<endl;
                    e=i;
                    f=j;
                    break;
                }
                case 'L':{
                    //cout<<i<<' '<<j<<endl;
                    x=i;
                    y=j;
                    break;
                }
            }
        }
    }
    //cout<<a<<' '<<b<<endl<<e<<' '<<f<<endl<<x<<' '<<y<<endl;
    if(a==e&&a==x&&f>min(b,y)&&f<max(b,y)){
        write(abs(b-y)+1);
    }
    else if(b==f&&b==y&&e>min(a,x)&&e<max(a,x)){
        write(abs(a-x)+1);
    }
    else write(abs(a-x)+abs(b-y)-1);
    return 0;
}