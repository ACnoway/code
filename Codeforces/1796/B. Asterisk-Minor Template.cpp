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
int t;
string a,b;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a[0]==b[0]){
            cout<<"YES"<<endl;
            putchar(a[0]);
            putchar('*');
            putchar('\n');
            continue;
        }
        else if(a[a.size()-1]==b[b.size()-1]){
            cout<<"YES"<<endl;
            putchar('*');
            putchar(a[a.size()-1]);
            putchar('\n');
            continue;
        }
        bool flag=0;
        for(int i=0;i+1<a.size();++i){
            for(int j=0;j+1<b.size();++j){
                if(a.substr(i,2)==b.substr(j,2)){
                    cout<<"YES"<<endl;
                    putchar('*');
                    putchar(a[i]);
                    putchar(a[i+1]);
                    putchar('*');
                    putchar('\n');
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}