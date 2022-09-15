#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000006;
char a[N],b[N];
int ne[N];
int main()
{
    scanf("%s%s",a+1,b+1);
    int na=strlen(a+1),nb=strlen(b+1);
    for(int i=2,j=0;i<=nb;++i){
        j=ne[i-1];
        while(j&&b[j+1]!=b[i]) j=ne[j];
        if(b[j+1]==b[i]) ne[i]=j+1;
    }
    for(int i=1,j=0;i<=na;++i){
        while(j&&b[j+1]!=a[i]) j=ne[j];
        if(b[j+1]==a[i]) j++;
        if(j==nb){
            j=ne[j];
            cout<<i-nb+1<<endl;
        }
    }
    for(int i=1;i<=nb;++i) cout<<ne[i]<<' ';
    return 0;
}