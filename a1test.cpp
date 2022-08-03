#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int f,n,k;
int e[N],ne[N];
int main()
{
    cin>>f>>n>>k;
    for(int i=0;i<n;++i){
        int addr;
        cin>>addr;
        cin>>e[addr]>>ne[addr];
    }
    for(int i=f;~i;i=ne[i]){
        printf("%05d %d %05d\n",i,e[i],ne[i]);
    }
    return 0;
}