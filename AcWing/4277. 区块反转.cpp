#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int f,n,k;
int e[N],ne[N];
int main()
{
    cin>>f>>n>>k;
    int addr;
    for(int i=0;i<n;++i){
        cin>>addr;
        cin>>e[addr]>>ne[addr];
    }
    int now=-1;
    for(int j=0;~j;){
        int tmp=f;
        j=f;
        for(int cnt=0;~j&&cnt<k;j=ne[j],cnt++) f=j;
        int tt=ne[f];
        ne[f]=now;
        f=tt;
        now=tmp;
    }
    for(int i=now;~i;i=ne[i]){
        printf("%05d %d ",i,e[i]);
        if(ne[i]!=-1) printf("%05d\n",ne[i]);
        else printf("-1\n");
    }
    return 0;
}