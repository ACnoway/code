#include<bits/stdc++.h>
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
    int a,b;
    bool operator<(const node&oth)const{
        return a<oth.a;
    }
};
set<node>s;
int main()
{
    s.insert({1,2});
    s.insert({1,3});
    printf("%d",(*s.lower_bound({1,4})).b);
    return 0;
}