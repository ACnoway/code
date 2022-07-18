#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
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
struct node{
    vector<int> ch;
    bool v;
    node(){ch.clear();v=false;}
}a[200005];
int n,m,s,t;
int b[200005],c[200005];
queue<int> q;
void bfs(){
    q.push(s);
    while(!(q.empty())){
        int x=q.front(),si=a[x].ch.size();
        q.pop();
        for(int i=0;i<si;++i){
            q.push(a[x].ch[i]);
        }
    }
}
int main()
{
    n=read();
    m=read();
    s=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        a[u].ch.push_back(v);
    }

    return 0;
}