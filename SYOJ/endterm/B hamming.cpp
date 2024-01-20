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
int n,l;
string a[N];
int ans[N];
int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>l;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int tmp=0;
            for(int k=0;k<l;++k){
                if(a[i][k]!=a[j][k]) ++tmp;
            }
            ans[i]=max(ans[i],tmp);
            ans[j]=max(ans[j],tmp);
        }
        cout<<ans[i]<<'\n';
    }
    return 0;
}
