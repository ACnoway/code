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
const int N=100005;
int n;
int a[N];

int main()
{
    /* freopen("magic.in","r",stdin); */
    n=read();
    long long qian=0,hou=0,ans=0;
    for(int i=1;i<=n;++i) a[i]=read(),hou+=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        hou-=a[i];
        ans+=hou-(long long)a[i]*(long long)(n-i);
    }
    printf("%lld\n",ans);
    return 0;
}
