#include<iostream>
#include<cstdio>
using namespace std;
char c,a;
int k,b,x,f=1,n=1;
//f表示正负，n表示当前在等号哪边，如果在等号右边就是-1
//因为要移项并变号
bool flag;
int main()
{
    while(cin>>c){
        if(c=='-'){
            b+=n*f*x;
            f=-1;
            x=0;
            flag=0;
        }
        else if(c=='+'){
            b+=n*f*x;
            f=1;
            x=0;
            flag=0;
        }
        else if(c=='='){
            b+=n*f*x;
            f=1;
            n=-1;
            x=0;
            flag=0;
        }
        else if(c>='a'&&c<='z'){
            if(flag){
                k+=n*f*x;
                x=0;
            }
            else k+=n*f;
            a=c;
            flag=0;
        }
        else if(c>='0'&&c<='9'){
            x=(x<<3)+(x<<1)+(c^48);
            flag=1;
        }
    }
    b+=n*f*x;
    double ans=double(-b*1.0/k);
    if(ans==-0.0) ans=0;
    printf("%c=%.3lf",a,ans);
    return 0;
}