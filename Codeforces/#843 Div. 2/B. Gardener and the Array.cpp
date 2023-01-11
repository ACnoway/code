#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int v[200005];
bool flag,now;
int t,n,k,x;
vector<int> a[100005];
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
    t=read();
    while(t--){
        n=read();
        now=1;
        debug(n);
        for(int i=0;i<=n;++i) a[i].clear();
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;++i){
            k=read();
            flag=1;
            for(int j=1;j<=k;++j){
                x=read();
                a[i].push_back(x);
                debug(x);
                if(!v[x]){
                    flag=0;
                    v[x]=1;
                }
                else v[x]++;
            }
            if(flag){
                if(now) cout<<"Yes"<<endl,now=0;
                
            }
        }
        if(now==0) continue;
        for(int i=1;i<=n;++i){
            flag=1;
            for(int j:a[i]){
                if(v[j]==1){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(flag) continue;
        else cout<<"No"<<endl;
        
    }
    return 0;
}