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
const int N=32;
int n,m;
int cnt[130];
string a[N],b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        for(int j=0;j<m;++j) ++cnt[a[i][j]];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
        for(int j=0;j<m;++j) --cnt[b[i][j]];
    }
    if(cnt[(int)'#']||cnt[(int)'.']) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}