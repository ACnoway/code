#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
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
priority_queue<int> q;
priority_queue<int,vector<int>,greater<int> > qq;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int ans=0,aa=0;
    for(int i=1;i<=n;++i){
        q.push(a[i]);
        if(a[i]<q.top()){
            ans+=q.top()-a[i];
            q.pop();
            q.push(a[i]);
        }
    }
    for(int i=1;i<=n;++i){
        qq.push(a[i]);
        if(a[i]>qq.top()){
            aa+=a[i]-qq.top();
            qq.pop();
            qq.push(a[i]);
        }
    }
    printf("%d\n",min(ans,aa));
    return 0;
}
