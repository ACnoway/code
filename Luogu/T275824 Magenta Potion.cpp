#include<iostream>
#define int register int
using namespace std;
inline signed read(){
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
signed n,q;
signed a[200005],fu[200005];
signed main()
{
    n=read();
    q=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        fu[i]=fu[i-1];
        if(a[i]<0) fu[i]++;
    }
    int op,x,y,d,p1,p2;
    bool flag;
    long long ans=1,t1=1,t2=1;
    while(q--){
        op=read();
        x=read();
        y=read();
        if(op==1){
            if(a[x]<0&&y>0) d=-1;
            else if(a[x]>0&&y<0) d=1;
            else d=0;
            a[x]=y;
            for(int i=x;i<=n;++i) fu[i]+=d;
        }
        else{
            ans=1; t1=1; t2=1;
            flag=1;
            if((fu[y]-fu[x-1])&1){
                for(int i=x;i<=y;++i){
                    if(a[i]<0){
                        p1=i;
                        break;
                    }
                }
                for(int i=y;i>=x;--i){
                    if(a[i]<0){
                        p2=i;
                        break;
                    }
                }
                for(int i=x;i<p2;++i){
                    t1*=a[i];
                    if(abs(t1)>(1<<30)){
                        flag=0;
                        break;
                    }
                }
                if(!flag){
                    cout<<"Too large"<<endl;
                    continue;
                }
                for(int i=y;i>p1;--i){
                    t2*=a[i];
                    if(abs(t2)>(1<<30)){
                        flag=0;
                        break;
                    }
                }
                if(!flag){
                    cout<<"Too large"<<endl;
                    continue;
                }
                cout<<max(t1,t2);putchar('\n');
            }
            else{
                for(int i=x;i<=y;++i){
                    ans*=a[i];
                    if(abs(ans)>(1<<30)){
                        flag=0;
                        break;
                    }
                }
                if(flag) cout<<ans,putchar('\n');
                else cout<<"Too large"<<endl;
            }
        }
    }
    return 0;
}