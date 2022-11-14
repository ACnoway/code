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
int w,h,ww,hh;
int main()
{
    cin>>w>>h>>ww>>hh;
    int wn=ww+ww-1,hn=hh+hh-1;
    int wc=w/wn,hc=h/hn;
    if(w%wn>=ww) wc++;
    if(h%hn>=hh) hc++;
    cout<<wc*hc<<endl;
    return 0;
}