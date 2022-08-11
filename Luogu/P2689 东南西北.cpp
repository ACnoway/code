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
int xa,ya,xb,yb;
int t,ans,bei,south,xi,dong,cnt;
char c;
int main()
{
    cin>>xa>>ya>>xb>>yb;
    cin>>t;
    if(xb-xa>0){
        dong=xb-xa;
        cnt++;
    }
    else if(xb-xa<0){
        xi=xa-xb;
        cnt++;
    }
    if(yb-ya>0){
        bei=yb-ya;
        cnt++;
    }
    else if(yb-ya<0){
        south=ya-yb;
        cnt++;
    }
    ans=dong+south+xi+bei;
    for(int i=1;i<=t;++i){
        cin>>c;
        switch(c){
            case 'E':
                if(dong) dong--;
                break;
            case 'S':
                if(south) south--;
                break;
            case 'W':
                if(xi) xi--;
                break;
            case 'N':
                if(bei) bei--;
                break;
        }
        if(!(dong||south||xi||bei)){
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}