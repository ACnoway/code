#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int T,n,k;
string s,t;
int tong[27],p[200005],pt[200005][27];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int x,int y){
    int xx=find(x),yy=find(y);
    for(int i=0;i<26;++i) pt[xx][i]+=pt[yy][i],pt[yy][i]=pt[xx][i];
    p[xx]=yy;
}
int main()
{
    cin>>T;
    while(T--){
        cin>>n>>k;
        cin>>s>>t;
        for(int i=0;i<26;++i) tong[i]=0;
        for(int i=0;i<n;++i){
            p[i]=i;
            tong[s[i]-'a']++;
            tong[t[i]-'a']--;
            for(int j=0;j<26;++j) pt[i][j]=0;
            pt[i][s[i]-'a']++;
            pt[i][t[i]-'a']--;
        }
        bool flag=1;
        for(int i=0;i<26;++i){
            if(tong[i]!=0){
                flag=0;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n;++i){
            if(i+k<n&&find(i)!=find(i+k)){
                merge(i,i+k);
            }
            if(i+k+1<n&&find(i)!=find(i+k+1)){
                merge(i,i+k+1);
            }
            /*if(i-k>=0&&find(i)!=find(i-k)){
                merge(i,i-k);
            }
            if(i-k-1>=0&&find(i)!=find(i-k-1)){
                merge(i,i-k-1);
            }*/
        }
        for(int i=0;i<n;++i){
            flag=1;
            if(p[i]==i){
                for(int j=0;j<26;++j){
                    if(pt[i][j]!=0){
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}