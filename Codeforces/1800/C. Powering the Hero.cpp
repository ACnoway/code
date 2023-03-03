#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define int long long
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
int t,n,ans;
int a[200005];
priority_queue<int> p;
signed main()
{
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i) a[i]=read();
        for(int i=n;i;--i){
            if(a[i]==0) p.push(a[i]);
            else{
                if(!p.empty()&&a[i]>-p.top()){
                    p.pop();
                    p.push(-a[i]);
                }
            }
        }
        while(!p.empty()){
            ans+=p.top();
            p.pop();
        }
        write(-ans);
        putchar('\n');
    }
    return 0;
}