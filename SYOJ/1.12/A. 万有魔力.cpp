#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int read(){
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
const int N=50004;
int n;
typedef pair<int,int> pii;
pii a[N];
int main()
{
    n=read();
    int qian=0,hou=0;
    for(int i=1;i<=n;++i){
        a[i].first=read(),a[i].second=read();
        hou+=a[i].second;
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j)
            ans+=abs(a[i].second-a[j].second)*a[i].first;
    }
    printf("%lld\n",ans);
    return 0;
}
