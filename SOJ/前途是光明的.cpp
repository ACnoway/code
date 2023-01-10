#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstdlib>
#define pii pair<int,int>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
map<pii,int> v;
string s;
int sx,sy,nx,ny,k,sum,ans,nope;
int main()
{
    cin>>s;
    cin>>k;
    v[(pii){sx,sy}]=1;
    sum++;
    for(int i=0;i<s.size();++i){
        switch (s[i])
        {
        case 'U':
            ny++;
            break;
        case 'D':
            ny--;
            break;
        case 'L':
            nx--;
            break;
        case 'R':
            nx++;
            break;
        }
        if(!v[(pii){nx,ny}]){
            v[(pii){nx,ny}]=1;
            sum++;
        }
    }
    for(int i=0;i<s.size();++i){
        switch (s[i])
        {
        case 'U':
            ny++;
            break;
        case 'D':
            ny--;
            break;
        case 'L':
            nx--;
            break;
        case 'R':
            nx++;
            break;
        }
        if(!v[(pii){nx,ny}]){
            v[(pii){nx,ny}]=2;
        }
        else{
            nope++;
        }
    }
    cout<<sum*k-nope*(k-1)<<endl;
    return 0;
}