#include<bits/stdc++.h>
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
int T,l,n,now,cnt;
//* 1黑0白
bool a[2][602][602];
bool C(int i,int j){
    while(i&&j){
        if(!(i&1)&&(j&1)) return 0;
        i>>=1;
        j>>=1;
    }
    return 1;
}
/*
 * 把两个或零个就染黑的改成一个或三个
 * 这样的话奇数层就会跟之前的答案相反，最后要取反
 * 白色为0黑色为1，将方案数的奇偶性异或起来，判断最后的奇偶
*/
int main()
{
    srand(time(0)+603);
    T=read();
    while(T--){
        l=read(); n=read();
        if(n==0){
            if(l&1) printf("White\n");
            else printf("Black\n");
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            int x=read(),y=read();
            ans^=(C(l-1,x-1)*C(x-1,y-1));
        }
        ans^=(l&1)^1;
        if(ans) printf("Black\n");
        else printf("White\n");
    }
    return 0;
}