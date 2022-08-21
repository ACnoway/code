#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int a[10];
string ans[2]={"",""};
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
int main()
{
    int wi;
    for(int i=0;i<=9;++i) a[i]=read();
    for(int i=9;i>=0;--i){
        if(a[i]&1){
            wi=1;
            break;
        }
    }
    if(wi==0){
        for(int i=9;i>=0;--i){
            for(int j=0;j<a[i];++j){
                ans[j&1]+=i+'0';
            }
        }
        cout<<ans[0]<<endl<<ans[1];
        return 0;
    }
    int now=0,nw=9;
    while(1){
        while(nw>=0&&!a[nw]) --nw;
        if(nw==-1){
            cout<<ans[0]<<endl<<ans[1];
            return 0;
        }
        while(a[nw]){
            if(ans[0].size()!=ans[1].size()){
                if(ans[1].size()>ans[0].size()) ans[0]+=nw+'0';
                else ans[1]+=nw+'0';
            }
            else{
                if(wi) ans[0]+=nw+'0',wi=0;
                else ans[1]+=nw+'0';
            }
            a[nw]--;
        }
    }
    cout<<ans[0]<<endl<<ans[1];
    return 0;
}