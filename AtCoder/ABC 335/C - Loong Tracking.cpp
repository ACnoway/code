#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
typedef pair<int,int> pii;
vector<pii> a;
int n,q,x,y;

int main()
{
    n=read();
    q=read();
    x=1,y=0;
    for(int i=n;i;--i) a.push_back({i,0});
    for(int i=1;i<=q;++i){
        int op=read();
        if(op==1){
            char c=getchar();
            if(c=='R')
                x+=1;
            else if(c=='L')
                x-=1;
            else if(c=='U')
                y+=1;
            else
                y-=1;
            a.push_back({x,y});
        }
        else{
            int c=read();
            printf("%d %d\n",a[a.size()-c].first,a[a.size()-c].second);
        }
    }
    return 0;
}
