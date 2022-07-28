#include <iostream>
#include <cstdio>
#include <cmath>
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
int n,ans;
int x[103],y[103];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        x[i]=read();
        y[i]=read();
    }
    for(int i=1;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<=n;++k){
                if(x[i]==x[j]){
                    if(y[j]==y[k])
                        ans=max(ans,abs(y[i]-y[j])*abs(x[j]-x[k]));
                    else if(y[i]==y[k])
                        ans=max(ans,abs(y[i]-y[j])*abs(x[i]-x[k]));
                }
                else if(x[i]==x[k]){
                    if(y[i]==y[j])
                        ans=max(ans,abs(y[i]-y[k])*abs(x[i]-x[j]));
                    else if(y[j]==y[k])
                        ans=max(ans,abs(y[i]-y[k])*abs(x[j]-x[k]));
                }
                else if(x[j]==x[k]){
                    if(y[i]==y[j])
                        ans=max(ans,abs(y[k]-y[j])*abs(x[j]-x[i]));
                    else if(y[i]==y[k])
                        ans=max(ans,abs(y[k]-y[j])*abs(x[i]-x[k]));
                }
            }
        }
    }
    write(ans);
    return 0;
}