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
const int N=10004;
typedef pair<int,int> pii;
int n,m;
pii a[N];
int ans[N];
int main()
{
    n=read();
    m=read();
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x=read();
            //记录aker位置
            if(x) a[++cnt]={i,j};
        }
    }
    //初始化ans数组
    for(int i=1;i<=m;++i) ans[i]=1145141919;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            if(i==j) continue;
            //算最小曼哈顿距离
            ans[j]=min(ans[j],abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
        }
    }
    int Ans=0;
    //找最大的也就是最晚结束的
    for(int i=1;i<=m;++i) Ans=max(Ans,ans[i]);
    printf("%d\n",Ans);
    return 0;
}
/*
5 5
1 0 1 0 0
1 0 0 0 0
0 0 0 0 0
1 0 0 0 0
0 0 0 0 1
*/