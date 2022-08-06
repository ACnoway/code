#include<iostream>
using namespace std;
int a[100005];
int n,m;
inline int lowbit(int x){
    return x&(-x);
}
int main()
{
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;++i){
        cin>>m;
        ans+=i-1;
        //将之前的数的数量都加上，然后减去正序对的数量就是逆序对的数量
        for(int j=m;j;j-=lowbit(j)) ans-=a[j];
        for(int j=m;j<=n;j+=lowbit(j)) a[j]++;
    }
    cout<<ans<<endl;
    return 0;
}