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
typedef unsigned long long ull;
const int P=10;
const ull M=1000000007;
ull a[1000006],b[1000006],p[1000006];
int n,temp;
char s[1000006];
string ans;
ull get(int l,int r){
    return (a[r]+M-(a[l]*p[r-l])%M)%M;
}
int check(int x){
    if(n>3*x){
        if((n-x)&1){ //* x a a+1 
            temp=(n-x)>>1;
            if((a[x]+get(x,temp+x))%M==get(temp+x,n)) return temp+x;
            else return -1;
        }
        else{ //* x a a
            temp=(n-x)>>1;
            if((a[x]+get(x,temp+x))%M==get(temp+x,n)) return temp+x;
            else return -1;
        }
    }
    else{
        if(n>2*x){ //* x a x
            temp=n-x-x;
            if((a[x]+get(x,temp+x))%M==get(temp+x,n)) return temp+x;
        }
        if(n>(2*x+1)){ //* x a x+1
            temp=n-x-x-1;
            if((a[x]+get(x,temp+x))%M==get(temp+x,n)) return temp+x;
        }
        return -1;
    }
    return -1;
}
int main()
{
    cin>>s+1;
    n=strlen(s+1);
    p[0]=1;
    for(int i=1;i<=n;++i){
        a[i]=(a[i-1]*P+(s[i]-'0'))%M;
        p[i]=(p[i-1]*P)%M;
    }
    int i,j;
    for(i=1;i<=n>>1;++i){
        temp=check(i);
        if(temp!=-1){
            if(temp-i>1&&s[i+1]=='0') continue;
            for(j=1;j<=i;++j) putchar(s[j]);
            putchar('+');
            for(;j<=temp;++j) putchar(s[j]);
            putchar('=');
            for(;j<=n;++j) putchar(s[j]);
            return 0;
        }
    }
    return 0;
}