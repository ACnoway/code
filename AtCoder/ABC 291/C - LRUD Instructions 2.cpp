#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<unordered_map>
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
unordered_map<string,bool> m;
int n,x,y,xx,yy;
string s,now;
int main()
{
    cin>>n>>s;
    m["0 0"]=1;
    for(int i=0;i<s.size();++i){
        if(s[i]=='R'){
            x++;
        }
        else if(s[i]=='L'){
            x--;
        }
        else if(s[i]=='U'){
            y++;
        }
        else y--;
        now="";
        xx=x;yy=y;
        if(y==0) now="0";
        while(yy){
            now=(char)(yy%10+'0')+now;
            yy/=10;
        }
        now=' '+now;
        if(x==0) now='0'+now;
        while(xx){
            now=(char)(xx%10+'0')+now;
            xx/=10;
        }
        if(m[now]){
            cout<<"Yes"<<endl;
            return 0;
        }
        else m[now]=1;
    }
    cout<<"No"<<endl;
    return 0;
}