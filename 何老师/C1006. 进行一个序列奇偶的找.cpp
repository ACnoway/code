#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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

const int maxn=50,mod=1000000007;
int n,m;
struct node
{
    int x,y;
    int w[2];
}a[maxn];

struct bian
{
    int to,nxt,val;
}e[202];
int idx,head[maxn];
void add(int u,int v,int w){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    e[idx].val=w;
    head[u]=idx;
}

//连通块大小
int cnt[maxn];
//前缀和的奇偶
int qian[maxn];
//f[u][0/1][0/1]
//表示qian_u=0/1,
//a_u=0/1时u到n的方案数
int f[maxn][3][3];
//ans[u][0/1][0/1]
//表示qian_u=0/1,
//a_u=0/1时u到n的最小字典序答案
int ans[maxn][3][3][maxn];

bool check(int x,int i,int j,int k,int o){
    for(int w=x+1;w<=n;++w){
        if(ans[x+1][i][j][w]<ans[x][k][o][w]) return 1;
        if(ans[x+1][i][j][w]>ans[x][k][o][w]) return 0;
    }
    return 1;
}
//从0开始，到n返回，回溯的时候处理答案序列和个数
void dfs(int x){
    if(x>n){
        return;
    }
    //将答案字典序弄成最大，待会min找最小字典序
    for(int i=1;i<=n;++i){
        ans[x][0][0][i]=a[i].y;
        ans[x][0][1][i]=a[i].y;
        ans[x][1][0][i]=a[i].y;
        ans[x][1][1][i]=a[i].y;
    }
    //f记录的是从u到n的方案数
    f[x][0][0]=0;
    f[x][0][1]=0;
    f[x][1][0]=0;
    f[x][1][1]=0;
    //如果x没有连边才能dp
    //连边了的已经被固定了
    if(cnt[x]==0){
        dfs(x+1);
        //漫长的分类讨论开始力
        if(qian[x+1]!=1){
            f[x][0][0]=(f[x][0][0]+f[x+1][0][0]*a[x].w[0]%mod)%mod;
            //比较字典序更新答案
            //这四个情况可以根据f数组的意思推一下，把奇偶关系搞清楚就OK了
            if(f[x+1][0][0]>0&&check(x,0,0,0,0)){
                for(int i=x+1;i<=n;++i){
                    ans[x][0][0][i]=ans[x+1][0][0][i];
                }
                ans[x][0][0][x]=(a[x].x+1)/2*2;
            }
            f[x][0][1]=(f[x][0][1]+f[x+1][0][0]*a[x].w[1]%mod)%mod;
            if(f[x+1][0][0]>0&&check(x,0,0,0,1)){
                for(int i=x+1;i<=n;++i){
                    ans[x][0][1][i]=ans[x+1][0][0][i];
                }
                ans[x][0][1][x]=a[x].x/2*2+1;
            }
            f[x][1][0]=(f[x][1][0]+f[x+1][0][1]*a[x].w[0]%mod)%mod;
            if(f[x+1][0][1]>0&&check(x,0,1,1,0)){
                for(int i=x+1;i<=n;++i){
                    ans[x][1][0][i]=ans[x+1][0][1][i];
                }
                ans[x][1][0][x]=(a[x].x+1)/2*2;
            }
            f[x][1][1]=(f[x][1][1]+f[x+1][0][1]*a[x].w[1]%mod)%mod;
            if(f[x+1][0][1]>0&&check(x,0,1,1,1)){
                for(int i=x+1;i<=n;++i){
                    ans[x][1][1][i]=ans[x+1][0][1][i];
                }
                ans[x][1][1][x]=a[x].x/2*2+1;
            }
        }
        if(qian[x+1]!=0){
            f[x][0][0]=(f[x][0][0]+f[x+1][1][1]*a[x].w[0]%mod)%mod;
            if(f[x+1][1][1]>0&&check(x,1,1,0,0)){
                for(int i=x+1;i<=n;++i){
                    ans[x][0][0][i]=ans[x+1][1][1][i];
                }
                ans[x][0][0][x]=(a[x].x+1)/2*2;
            }
            f[x][0][1]=(f[x][0][1]+f[x+1][1][1]*a[x].w[1]%mod)%mod;
            if(f[x+1][1][1]>0&&check(x,1,1,0,1)){
                for(int i=x+1;i<=n;++i){
                    ans[x][0][1][i]=ans[x+1][1][1][i];
                }
                ans[x][0][1][x]=a[x].x/2*2+1;
            }
            f[x][1][0]=(f[x][1][0]+f[x+1][1][0]*a[x].w[0]%mod)%mod;
            if(f[x+1][1][0]>0&&check(x,1,0,1,0)){
                for(int i=x+1;i<=n;++i){
                    ans[x][1][0][i]=ans[x+1][1][0][i];
                }
                ans[x][1][0][x]=(a[x].x+1)/2*2;
            }
            f[x][1][1]=(f[x][1][1]+f[x+1][1][0]*a[x].w[1]%mod)%mod;
            if(f[x+1][1][0]>0&&check(x,1,0,1,1)){
                for(int i=x+1;i<=n;++i){
                    ans[x][1][1][i]=ans[x+1][1][0][i];
                }
                ans[x][1][1][x]=a[x].x/2*2+1;
            }
        }
        return;
    }
    int st[50],top;
    int p,v;
    if(qian[x]!=1){
        //* 枚举跟x相连的点的前缀和的奇偶并dfs，后面回溯时再弄成-1
        p=0;
        for(int i=head[x];i;i=e[i].nxt){
            v=e[i].to;
            if(qian[v]!=-1&&qian[v]!=0^e[i].val){
                p=1;
            }
        }
        if(p==0){
            top=0;
            int t=qian[x];
            qian[x]=0;
            for(int i=head[x];i;i=e[i].nxt){
                v=e[i].to;
                if(qian[v]==-1){
                    //定好v的前缀和的奇偶
                    qian[v]=qian[x]^e[i].val;
                    st[++top]=v;
                }
            }
            dfs(x+1);
            if(qian[x+1]!=1){
                f[x][0][0]=(f[x][0][0]+f[x+1][0][0]*a[x].w[0]%mod)%mod;
                if(f[x+1][0][0]>0&&check(x,0,0,0,0)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][0][0][i]=ans[x+1][0][0][i];
                    }
                    ans[x][0][0][x]=(a[x].x+1)/2*2;
                }
                f[x][0][1]=(f[x][0][1]+f[x+1][0][0]*a[x].w[1]%mod)%mod;
                if(f[x+1][0][0]>0&&check(x,0,0,0,1)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][0][1][i]=ans[x+1][0][0][i];
                    }
                    ans[x][0][1][x]=a[x].x/2*2+1;
                }
            }
            if(qian[x+1]!=0){
                f[x][0][0]=(f[x][0][0]+f[x+1][1][1]*a[x].w[0]%mod)%mod;
                if(f[x+1][1][1]>0&&check(x,1,1,0,0)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][0][0][i]=ans[x+1][1][1][i];
                    }
                    ans[x][0][0][x]=(a[x].x+1)/2*2;
                }
                f[x][0][1]=(f[x][0][1]+f[x+1][1][1]*a[x].w[1]%mod)%mod;
                if(f[x+1][1][1]>0&&check(x,1,1,0,1)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][0][1][i]=ans[x+1][1][1][i];
                    }
                    ans[x][0][1][x]=a[x].x/2*2+1;
                }
            }
            qian[x]=t;
            for(int i=1;i<=top;++i)
                qian[st[i]]=-1;
        }
    }
    if(qian[x]!=0){
        p=0;
        for(int i=head[x];i;i=e[i].nxt){
            v=e[i].to;
            if(qian[v]!=-1&&qian[v]!=1^e[i].val){
                p=1;
            }
        }
        if(p==0){
            top=0;
            int t=qian[x];
            qian[x]=1;
            for(int i=head[x];i;i=e[i].nxt){
                v=e[i].to;
                if(qian[v]==-1){
                    qian[v]=qian[x]^e[i].val;
                    st[++top]=v;
                }
            }
            dfs(x+1);
            if(qian[x+1]!=1){
                f[x][1][0]=(f[x][1][0]+f[x+1][0][1]*a[x].w[0]%mod)%mod;
                if(f[x+1][0][1]>0&&check(x,0,1,1,0)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][1][0][i]=ans[x+1][0][1][i];
                    }
                    ans[x][1][0][x]=(a[x].x+1)/2*2;
                }
                f[x][1][1]=(f[x][1][1]+f[x+1][0][1]*a[x].w[1]%mod)%mod;
                if(f[x+1][0][1]>0&&check(x,0,1,1,1)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][1][1][i]=ans[x+1][0][1][i];
                    }
                    ans[x][1][1][x]=a[x].x/2*2+1;
                }
            }
            if(qian[x+1]!=0){
                f[x][1][0]=(f[x][1][0]+f[x+1][1][0]*a[x].w[0]%mod)%mod;
                if(f[x+1][1][0]>0&&check(x,1,0,1,0)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][1][0][i]=ans[x+1][1][0][i];
                    }
                    ans[x][1][0][x]=(a[x].x+1)/2*2;
                }
                f[x][1][1]=(f[x][1][1]+f[x+1][1][0]*a[x].w[1]%mod)%mod;
                if(f[x+1][1][0]>0&&check(x,1,0,1,1)){
                    for(int i=x+1;i<=n;++i){
                        ans[x][1][1][i]=ans[x+1][1][0][i];
                    }
                    ans[x][1][1][x]=a[x].x/2*2+1;
                }
            }
            qian[x]=t;
            for(int i=1;i<=top;++i)
                qian[st[i]]=-1;
        }
    }
}

signed main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i].x=read();
        a[i].y=read();
        qian[i]=-1;
        cnt[i]=0;
        a[i].w[1]=a[i].w[0]=(a[i].y-a[i].x+1)/2;
        if(a[i].x%2==a[i].y%2){
            if(a[i].x%2){
                a[i].w[1]++;
            }
            else{
                a[i].w[0]++;
            }
        }
    }
    cnt[0]=0;
    a[0].w[0]=1;
    a[0].w[1]=1;
    qian[n+1]=-1;
    int u,v,w;
    for(int i=1;i<=m;++i){
        u=read();
        v=read();
        w=read();
        u--;
        cnt[u]++;
        cnt[v]++;
        add(u,v,w);
    }
    //先根据连的边把最开始的前缀和奇偶找出来
    for(int i=head[0];i;i=e[i].nxt){
        v=e[i].to;
        qian[v]=e[i].val;
    }
    f[n+1][0][0]=f[n+1][1][0]=1;
    dfs(0);
    write(f[0][0][0]);
    putchar('\n');
    if(f[0][0][0]){
        for(int i=1;i<=n;++i){
            write(ans[0][0][0][i]);
            putchar(' ');
        }
    }
    else write(-1);
    return 0;
}