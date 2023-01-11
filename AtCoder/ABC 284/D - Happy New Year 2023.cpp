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
ull n,ss;
ull primes[4000006];
bool p[4000006];
bool check(ull x){
    if(x==1||(x%2==0&&x!=2)) return 0;
    if(x==2) return 1;
    for(ull i=3;i*i<=x;i+=2){
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    for(int i=0;i<=3000006;++i) p[i]=1;
    p[0]=p[1]=0;
    for(int i=0;i<=3000006;++i){
        if(p[i]) primes[++primes[0]]=i;
        for(int j=1;j<=primes[0];++j){
            if(i*primes[j]>3000006) break;
            p[i*primes[j]]=0;
            if(i%primes[j]==0) break;
        }
    }
    //for(int i=1;i<=10;++i) cout<<primes[i]*primes[i]<<endl;
    ///*
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=primes[0];++i){
            if(n%primes[i]==0){
                if(n%(primes[i]*primes[i])==0){
                    ss=n/primes[i]/primes[i];
                    cout<<primes[i]<<' '<<ss<<endl;
                    break;
                }
                else{
                    ss=sqrt(n/primes[i]);
                    if(ss*ss==n/primes[i]&&check(ss)){
                        cout<<ss<<' '<<primes[i]<<endl;
                        break;
                    }
                }
            }
        }
    }
    //*/
    return 0;
}