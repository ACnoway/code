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
int main()
{
    int a[4],b[4];
    int ans[4];
    for(int i=0;i<4;++i) cin>>a[i]>>b[i];
    res[3]=b[3]-a[3];
    for(int i=2;i;--i){
        res[i]=res[i+1]+b[i]-a[i];
    }
    for(int i=1;i<=3;++i){
        cout<<res[i]<<endl;
    }
    return 0;
}