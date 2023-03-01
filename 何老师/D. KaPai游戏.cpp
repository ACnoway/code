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
const int inf=1145141919;
int n,ans=inf,cnt=-1;
struct node{
    int num[3];
}t[100005];
int fan[100005];
bool ton[100005];
inline bool check(){
    for(int i=0;i<=n*2;++i) ton[i]=0;
    for(int i=1;i<=n;++i){
        if(ton[t[i].num[fan[i]]]) return 0;
        else ton[t[i].num[fan[i]]]=1;
    }
    return 1;
}
void dfs(int x,int v){
    if(x>n){
        if(check()){
            if(ans>v){
                ans=v;
                cnt=1;
            }
            else if(ans==v) cnt++;
        }
        return;
    }
    dfs(x+1,v);
    fan[x]=1;
    dfs(x+1,v+1);
    fan[x]=0;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        t[i].num[0]=read();
        t[i].num[1]=read();
    }
    dfs(1,0);
    write((ans==inf?-1:ans%998244353));
    putchar(' ');
    write(cnt%998244353);
    return 0;
}