#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
typedef unsigned long long ull;
int t;
ull n;
ull primes[10000007];
bool p[10000007];
map<ull,bool> m;
int main()
{
    for(int i=0;i<=10000000;++i) p[i]=1;
    p[0]=p[1]=0;
    for(int i=0;i<=10000000;++i){
        if(p[i]){
            primes[++primes[0]]=i;
            m[i*i]=1;
            for(int j=2*i;j<=10000000;j+=i){
                p[j]=0;
            }
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;primes[i]<=n;++i){
            if(n%primes[i]==0&&m[n/primes[i]]){
                cout<<sqrt(n/primes[i])<<' '<<primes[i]<<endl;
                break;
            }
        }
    }
    return 0;
}