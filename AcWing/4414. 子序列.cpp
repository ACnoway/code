#include <iostream>
#include <cstdio>
#include <algorithm>
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
int n,ans,temp;
int a[100005],b[100005];
int main()
{
    n=read();
    a[1]=100005;
    b[1]=100005;
    for(int i=0;i<n;++i){
        temp=read();
        if(temp>0){
            ans+=temp;
            if(temp&1) a[++a[0]]=temp;
        }
        else{
            if(temp&1) b[++b[0]]=temp;
        }
    }
    sort(a+1,a+a[0]+1);
    sort(b+1,b+b[0]+1,greater<int>());
    if(ans&1) write(ans);
    else write(ans-min(a[1],abs(b[1])));
    putchar('\n');
    return 0;
}