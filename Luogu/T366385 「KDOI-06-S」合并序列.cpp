#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=502;
int T,n;
int a[N];
vector<int> v,ans[N];
int main()
{
    T=read();
    while(T--){
        n=read();
        v.clear();
        v.push_back(0);
        for(int i=1;i<=n;++i) a[i]=read(),v.push_back(a[i]);
        if(n==1){
            printf("Huoyu\n0\n");
            continue;
        }
        else if(n==2){
            
            continue;
        }
        else if(n==3){
            if(a[1]^a[2]^a[3])printf("Shuiniao\n");
            else printf("Huoyu\n1 2 3\n");
            continue;
        }
        else if(n==4){
            if(!(a[1]^a[2]^a[4])) printf("Huoyu\n1 2 4\n");
            else if(!(a[1]^a[3]^a[4])) printf("Huoyu\n1 3 4\n");
            else printf("Shuiniao\n");
            continue;
        }
        else{
            int cnt=0;
            while(v.size()>1){
                for(int i=1;i<n;++i){
                    for(int j=i+1;j<n;++j){
                        for(int k=j+1;k<=n;++k){
                            if((v[i]^v[j]^v[k])==0){
                                ans[++cnt].push_back(i);
                                ans[cnt].push_back(j);
                                ans[cnt].push_back(k);
                                int ss=0;
                                for(int o=i;o<=k;++o) ss^=v[i];
                                v.erase(v.begin()+i,v.begin()+k);
                                v.insert(v.begin()+i,ss);
                            }
                        }
                    }
                }
            }
            printf("")
            for(int i=1;i<=cnt;++i)
        }
    }
    return 0;
}