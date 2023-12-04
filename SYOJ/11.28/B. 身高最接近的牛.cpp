#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
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
int n,x;
vector<int> a;
int main()
{
    n=read();
    x=read();
    a.push_back(x);
    for(int i=2;i<=n;++i){
        x=read();
        int aa=lower_bound(a.begin(),a.end(),x)-a.begin();
        if(aa==0){
            printf("%d %d\n",abs(a[aa]-x),aa+1);
        }
        else{
            if(abs(a[aa-1]-x)<=abs(a[aa]-x)) printf("%d %d\n",abs(a[aa-1]-x),aa);
            else printf("%d %d\n",abs(a[aa]-x),aa+1);
        }
        a.insert(upper_bound(a.begin(),a.end(),x),x);
    }
    return 0;
}
