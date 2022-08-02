#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
const int N=100010;
int f1,f2,n;
int e[N],ne[N];
vector<int> a,b,res;
int main()
{
    cin>>f1>>f2>>n;
    for(int i=0;i<n;++i){
        int addr;
        cin>>addr;
        cin>>e[addr]>>ne[addr];
    }
    for(int i=f1;~i;i=ne[i]) a.push_back(i);
    for(int i=f2;~i;i=ne[i]) b.push_back(i);
    if(a.size()<b.size()) swap(a,b);
    reverse(b.begin(),b.end());
    for(int i=0,j=0;i<a.size();){
        res.push_back(a[i++]);
        if(i%2==0&&j<b.size()) res.push_back(b[j++]);
    }
    for(int i=0;i<res.size();++i){
        printf("%05d %d ",res[i],e[res[i]]);
        if(i==res.size()-1) printf("-1\n");
        else printf("%05d\n",res[i+1]);
    }
    return 0;
}