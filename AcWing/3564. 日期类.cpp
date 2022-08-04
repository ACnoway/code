#include<cstdio>
#include<iostream>
using namespace std;
int a[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int t,y,m,d;
int main()
{
    cin>>t;
    while(t--){
        cin>>y>>m>>d;
        if(m==12&&d==31) y++,m=d=1;
        else if(d<a[m]) d++;
        else m++,d=1;
        printf("%d-%02d-%02d\n",y,m,d);
    }
}