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
bool v[1001];
int n,k,w;
int main()
{
    cin>>n>>k;
    for(int i=0;i<1001;++i) v[i]=true;
    for(int i=2;i<=n;++i){
        if(v[i]){
            for(int j=i;j<=n;j+=i){
                if(v[j]){
                    w++;
                    v[j]=false;
                    if(w==k){
                        cout<<j;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}