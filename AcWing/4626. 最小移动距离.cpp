#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n;
int a[102],f[102];
bool v[102];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans=-1,now,cnt=0;
    bool flag=1;
    for(int i=1;i<=n;++i){
        cnt=0;
        now=a[i];
        flag=1;
        f[++cnt]=i;
        for(int j=1;j<=n;++j) v[j]=0;
        while(now!=i){
            if(v[i]){
                flag=0;
                break;
            }
            v[i]=1;
            f[++cnt]=now;
            now=a[now];
        }
        ++cnt;
        if(flag){
            
        }
    }
    return 0;
}