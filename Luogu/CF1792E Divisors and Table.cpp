#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define int long long
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
int t,n,m1,m2;
vector<int> s,s1,s2;
signed main()
{
    t=read();
    while(t--){
        n=read();
        m1=read();
        m2=read();
        s.clear();
        s1.clear();
        s2.clear();
        //处理约数
        for(int i=1;i*i<=m1;++i){
            if(m1%i==0){
                s1.push_back(i);
                s1.push_back(m1/i);
            }
        }
        for(int i=1;i*i<=m2;++i){
            if(m2%i==0){
                s2.push_back(i);
                s2.push_back(m2/i);
            }
        }
        //合起来
        for(auto x:s1){
            for(auto y:s2){
                s.push_back((int)x*(int)y);
            }
        }
        sort(s.begin(),s.end());
        //去重
        auto ptr=unique(s.begin(),s.end());
        int ans=0,cnt=0,x,l,r,st,mid;
        for(auto it=s.begin();it!=ptr;++it){
            x=*it;
            //二分找最大的
            l=0;r=it-s.begin();
            while(l<=r){
                mid=(l+r)>>1;
                if(x/s[mid]<=n){
                    st=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            for(int i=st;i<s.size();++i){
                if(s[i]>n) break;
                //整除         不能超出n列
                if(x%s[i]==0&&x/s[i]<=n){
                    ans^=s[i];
                    cnt++;
                    break;
                }
            }
        }
        printf("%lld %lld\n",cnt,ans);
    }
    return 0;
}