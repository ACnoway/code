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
int t,n;
char s[100005];
int main()
{
    scanf("%d",&t);
    int mid;
    int flag;
    while(t--){
        flag=0;
        scanf("%d%s",&n,s+1);
        mid=(n>>1)+1;
        if(n&1){
            for(int i=1;i<=mid;++i){
                if(s[i]!=s[mid-i+mid]&&!flag){
                    flag=1;
                }
                else if(s[i]==s[mid-i+mid]&&flag==1) flag=2;
                else if(s[i]!=s[mid-i+mid]&&flag==2){
                    flag=3;
                    break;
                }
            }
        }
        else{
            for(int i=1;i<mid;++i){
                if(s[i]!=s[mid-i+mid-1]&&!flag){
                    flag=1;
                }
                else if(s[i]==s[mid-i+mid-1]&&flag==1) flag=2;
                else if(s[i]!=s[mid-i+mid-1]&&flag==2){
                    flag=3;
                    break;
                }
            }
        }
        if(flag==3){
            printf("No\n");
        }
        else printf("Yes\n");
    }
    return 0;
}