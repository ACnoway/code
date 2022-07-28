#include<iostream>
#include<cmath>
using namespace std;
int primes[100000002];
int main()
{
    int n,sum=0;
    cin>>n;
    if(n==1){cout<<"0"; return 0;}
    primes[++primes[0]]=1;
    primes[++primes[0]]=0;
    for(int i=2;i<=n;i++){
        if(!primes[i]){
            for(long long j=(long long)1*i*i;j<=n;j+=i){
                primes[j]=1;
            }
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
