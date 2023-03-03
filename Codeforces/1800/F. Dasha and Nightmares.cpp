#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n;
string s[200005];
unordered_map<vector<int>,int> m;
vector<int> ok[200005];
//二进制压位转成int，跟现在思路一样但是把vector换成int存
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        vector<int> tmp(27,-1);
        for(int j=0;j<s[i].size();++j){
            if(tmp[s[i][j]]==-1) tmp[s[i][j]]=1;
            else tmp[s[i][j]]=(tmp[s[i][j]]+1)%2;
        }
        tmp[26]=s[i].size()%2;
        ok[i]=tmp;
        m[tmp]++;
    }
    for(int i=1;i<=n;++i){
        vector<int> tmp(27,-1);
        for(int j=0;j<26;++j){
            if(ok[i][j]==-1){
                
            }
        }
    }
    return 0;
}