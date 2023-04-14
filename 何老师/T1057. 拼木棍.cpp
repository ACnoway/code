#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
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
const int N=1e5+10;
typedef pair<int,int> pii;
int n,cur;
int a[N];
vector<map<int,int> > b;
void dfs(int x,int step){
    if(x==0||b[cur].count(x)) return;
    b[cur][x]=step;
    dfs(x/2,step+1);
    dfs((x+1)/2,step+1);
}
int main()
{
    n=read();
    b.resize(n);
    for(int i=0;i<n;++i){
        a[i]=read();
        cur=i;
        dfs(a[i],0);
    }
    int ans=1e9;
    for(pii i:b[0]){
        int k=i.first,tmp=i.second,flag=1;
        for(int j=1;j<n;++j){
            if(b[j].count(k)){
                tmp+=b[j][k];
            }
            else{
                flag=0;
                break;
            }
        }
        if(flag) ans=min(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}