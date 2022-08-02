#include<iostream>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int q=(n-m)/2;
    int c=0;
    string s="";
    for(int i=0;i<q;++i){
        if(c<k) s+='l',c++;
        else if(c<2*k-1) s+='r',c++;
        if(c==2*k-1) c=0;
    }
    
    return 0;
}