#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int a[15][70];
int d,t,ans,all;
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
    srand(time(0));
    //freopen(".\\wa.in","w",stdout);
    int d=500;
    cout<<d<<endl;
    for(int i=1;i<=d;++i) cout<<((rand()+rand()+1)*rand())%1000000000+1<<endl;
    return 0;
}