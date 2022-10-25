#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,r,c;
char a[101];
int main()
{
    cin>>a;
    n=strlen(a);
    for(int i=floor(sqrt(n));i>=1;--i)
        if(n%i==0){
            r=i;
            c=n/i;
            break;
        }
    for(int i=0;i<r;++i) for(int j=0;j<c;++j) putchar(a[j*r+i]);
    return 0;
}