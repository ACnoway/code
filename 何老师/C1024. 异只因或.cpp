#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define int long long
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
//注意trie树的宽度，这里因为最多是2的30次方所以要乘以30
const int maxn=500005*31;
int ch[maxn][2];
int bits[40][5];
int siz[maxn],budui[maxn];
int n,cnt,a,ans;
void insert(int x){
    int now=1,d;
    ++siz[now];
    for(int i=29;i>=0;--i){
        d=(x>>i)&1ll;
        //如果没孩子就新建个孩子
        if(!ch[now][d]){
            ch[now][d]=++cnt;
        }
        //转到孩子
        now=ch[now][d];
        //统计违法的方案个数，加上这一位之前已经插入的个数
        budui[now]+=bits[i][d];
        ++bits[i][d];
        ++siz[now];
    }
}
int query(int x){
    int sum=0,tmp,now=1,d;
    for(int i=29;i>=0;--i){
        d=(x>>i)&1ll;
        tmp=siz[ch[now][!d]]*bits[i][!d]-siz[ch[now][!d]]-budui[ch[now][!d]];
        sum+=tmp;
        now=ch[now][d];
        if(!now) break;
    }
    return sum;
}
signed main()
{
    n=read();
    cnt=1;
    for(int i=1;i<=n;++i){
        a=read();
        ans+=query(a);
        insert(a);
    }
    write(ans);
    putchar('\n');
    return 0;
}