#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
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
int n,q;
multiset<int> yi[200005];
set<int> er[200005];
int main()
{
    n=read();
    q=read();
    while(q--){
        int op=read(),x=read();
        if(op==1){
            int y=read();
            yi[y].insert(x);
            er[x].insert(y);
        }
        else if(op==2){
            for(auto i:yi[x]){
                cout<<i<<' ';
            }
            cout<<endl;
        }
        else{
            for(auto i:er[x]){
                cout<<i<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}