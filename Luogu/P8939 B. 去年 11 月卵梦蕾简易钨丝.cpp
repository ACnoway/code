#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,q,op,x,mi,ma;
multiset<int> s;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    n=read();
    q=read();
    while(n--){
        x=read();
        s.insert(x);
    }
    while(q--){
        op=read();x=read();
        if(op==1){
            if(s.find(x)==s.end()){
                write(-1),putchar('\n');
                continue;
            }
            else s.erase(s.find(x));
        }
        else s.insert(x);
        write(*(--s.end())-*(s.begin())+*(--s.end())-*(s.begin()));
        putchar('\n');
    }
    return 0;
}