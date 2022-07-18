#include <iostream>
#include <cstdio>
#include <cmath>
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
int t,n;
int ton[15];
int main()
{
    t=read();
    while(t--){
        for(int i=0;i<15;++i) ton[i]=0;
        n=read();
        int ans=0;
        bool flag=true;
        for(int i=1;i<=n;++i){
            int b,d;
            b=read();
            d=read();
            ton[d]=max(ton[d],b);
        }
        if(n<10){
            cout<<"MOREPROBLEMS"<<endl;
            continue;
        }
        for(int i=1;i<=10;++i){
            if(ton[i]==0){
                cout<<"MOREPROBLEMS"<<endl;
                flag=false;
                break;
            }
            ans+=ton[i];
        }
        if(!flag) continue;
        write(ans);
        putchar('\n');
    }
    return 0;
}