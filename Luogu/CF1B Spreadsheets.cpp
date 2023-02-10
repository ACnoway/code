#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int t,x,y,xx,yy;
char s[10000];
string ans;
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        if(sscanf(s,"R%dC%d",&x,&y)==2){
            ans="";
            // y--;
            while(y){
                ans=(char)((y-1)%26+'A')+ans;
                y=y/26;
            }
            cout<<ans<<x<<endl;
        }
        else{
            x=0;
            int i;
            for(i=0;i<strlen(s);++i){
                if(s[i]>='0'&&s[i]<='9') break;
                x=x*26+(s[i]-'A'+1);
            }
            putchar('R');
            for(;i<strlen(s);++i){
                putchar(s[i]);
            }
            cout<<'C'<<x<<endl;
        }
    }
    return 0;
}