#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
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
int n,q;
int a[200];
int main()
{
    n=read();
    q=read();
    int op,x;
    while(q--){
        op=read();
        x=read();
        if(op==1){
            a[x]+=1;
        }
        else if(op==2) a[x]+=2;
        else{
            if(a[x]>=2) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}