#include<iostream>
#include<list>
#include<vector>
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
const int maxn=5003;
int n,ans,cnt;
int a[maxn],f1[maxn],f2[maxn];
list<int> p1[maxn],p2[maxn];
vector<int> p[maxn];
int bef[maxn][maxn];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        p[a[i]].push_back(i);
    }
    int mid;
    bool flag;
    for(int i=1;i<=n;++i){
        for(int j=0;j<p[a[i]].size();++j){
            if(p[i][j]<=i) continue;
            mid=(p[i][j]+i)>>1;
            flag=1;
            for(int k=p[i][j]+1;k<=mid;++k){
                //不下降
                if(a[k]>a[k-1]){
                    flag=0;
                    break;
                }
                //回文
                if((p[i][j]-i+1)&1){
                    if(a[i]!=a[mid+mid-i]){
                        flag=0;
                        break;
                    }
                }
                else{
                    if(a[i]!=a[mid+mid-i+1]){
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag) continue;
            for(int k=1;k<=cnt;++k){
                for(int o=1;o<=ans;++o){
                    if()
                }
            }
        }
    }
    
    write(ans);
    putchar(' ');
    write(cnt);
    return 0;
}