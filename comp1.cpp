#include<iostream>
#define int __int128_t
using namespace std;
int n,q;
int a[200005];
signed main()
{
    n=read();
    q=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int op,x,y,ls;
    long long ans=1,tmp=1;
    while(q--){
        op=read();
        x=read();
        y=read();
        if(op==1) a[x]=y;
        else{
            ans=1;
            ls=1;
            for(int l=x;l<=y;++l){
                for(int r=l;r<=y;++r){
                    tmp=1;
                    for(int i=l;i<=r;++i){
                        tmp*=a[i];
                    }
                    ans=max(ans,tmp);
                }
            }
            if(ans<=(1<<30)) write(ans),putchar('\12');
            else cout<<"Too large"<<endl;
        }
    }
    return 0;
}