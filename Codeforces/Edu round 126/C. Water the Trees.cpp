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
int t,n,m,ans;
int a[300005],f[300005];
int main()
{
    t=read();
    while(t--){
        for(int i=0;i<=300004;++i) a[i]=0,f[i]=0;
        n=read();
        bool flag=false;
        m=0;
        ans=0;
        for(int i=1;i<=n;++i){
            a[i]=read();
            m=max(a[i],m);
        }
        if(m&1){
            for(int i=1;i<=n;++i){
                if(a[i]&1||a[i]==m) continue;
                flag=false;
                a[i]+=1;
                ans+=2;
                for(int j=1;j<=n;++j){
                    if(a[j]+2>m) continue;
                    a[j]+=2;
                    flag=true;
                    break;
                }
            }
            int cnt=0;
            for(int i=1;i<=n;++i){
                if(a[i]!=m) f[++cnt]=i;
            }
            if(cnt==0&&!flag){
                write(ans-1);
                putchar('\n');
                continue;
            }
            while(cnt){
                if(cnt>2){
                    if(a[cnt]&1){
                        a[cnt]++;
                        a[cnt-1]+=2;
                    }
                    else{
                        a[cnt-1]++;
                        a[cnt]+=2;
                    }
                    ans+=2;
                    if(a[cnt]==m) cnt--;
                    if(a[cnt]==m) cnt--;
                }
                else if(cnt==2){
                    if(a[cnt]&1){
                        a[cnt]++;
                        a[cnt-1]+=2;
                    }
                    else{
                        a[cnt-1]++;
                        a[cnt]+=2;
                    }
                    ans+=2;
                    if(a[cnt-1]==m){
                        a[cnt-1]=a[cnt];
                        cnt--;
                    }
                    if(a[cnt]==m) cnt--;
                }
                else{
                    a[cnt]+=((ans+1)&1?1:2);
                    if(a[cnt]>m){
                        a[cnt]=m;
                        ans+=2;
                    }
                    else ans+=1;
                    if(a[cnt]==m) cnt--;
                }
            }
            write(ans);
            putchar('\n');
        }
        else{
            for(int i=1;i<=n;++i){
                if(!(a[i]&1)||a[i]==m) continue;
                flag=false;
                a[i]+=1;
                ans+=2;
                for(int j=1;j<=n;++j){
                    if(a[j]+2>m) continue;
                    a[j]+=2;
                    flag=true;
                    break;
                }
            }
            int cnt=0;
            for(int i=1;i<=n;++i){
                if(a[i]!=m) f[++cnt]=a[i];
            }
            if(cnt==0&&!flag){
                write(ans-1);
                putchar('\n');
                continue;
            }
            //for(int i=1;i<=cnt;++i) cout<<f[i]<<' ';
            //cout<<endl;
            while(cnt){
                if(cnt>=2){
                    if(f[cnt]&1){
                        f[cnt]++;
                        f[cnt-1]+=2;
                    }
                    else{
                        f[cnt-1]++;
                        f[cnt]+=2;
                    }
                    ans+=2;
                    if(f[cnt-1]==m){
                        f[cnt-1]=f[cnt];
                        cnt--;
                    }
                    if(f[cnt]==m) cnt--;
                }
                else{
                    ans++;
                    if(m-f[cnt]==2){
                        ans+=ans&1;
                        break;
                    }
                    else if(m-f[cnt]==1){
                        ans+=(ans&1)^1;
                        break;
                    }
                    else if(m==f[cnt]){
                        ans--;
                        cnt--;
                    }
                    else{
                        f[cnt]+=(ans&1?1:2);
                    }
                }
            }
            write(ans);
            putchar('\n');
        }
    }
    return 0;
}