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
int t,n,d,h,ans,cnt;
int s[2000];
int main()
{
    t=read();
    while(t--){
        n=read();
        d=read();
        h=read();
        ans=1;
        cnt=0;
        for(int i=1;i<=n;++i){
            int temp=read();
            cnt+=temp;
            s[i]=temp*h;
            //cout<<temp<<' '<<s[i]<<' '<<cnt<<endl;
        }
        while(1){
            for(int i=1;i<=n;++i){
                int tcnt=cnt-s[i]/h;
                while((s[i]-d)%h!=0&&s[i]-d>0){
                    s[i]-=d;
                    cnt=tcnt+ceil((double)s[i]/h);
                    ans+=cnt;
                    cout<<i<<". sum= "<<s[i]<<"cnt= "<<cnt<<"ans= "<<ans<<endl;
                }
            }
            cout<<"----------------"<<endl;
            for(int i=1;i<=n;++i){
                int tcnt=cnt-s[i]/h;
                if(s[i]<=d) continue;
                s[i]-=d;
                cnt=tcnt+ceil((double)s[i]/h);
                ans+=cnt;
                cout<<i<<". sum= "<<s[i]<<"cnt= "<<cnt<<"ans= "<<ans<<endl;
            }
            bool flag=true;
            for(int i=1;i<=n;++i){
                if(s[i]>d) flag=false;
            }
            if(flag) break;
        }
        
        for(int i=1;i<=n;++i){
            ans+=n-i;
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}