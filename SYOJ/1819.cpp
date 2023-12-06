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
priority_queue<int,vector<int>,greater<int> > q;
int n;
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        int op=read();
        if(op==1){
            int x=read();
            q.push(x);
        }
        else if(op==2){
            if(!q.empty()) printf("%d\n",q.top());
        }
        else if(!q.empty()) q.pop();
    }
    return 0;
}
