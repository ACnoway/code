#include<iostream>
#include<cmath>
using namespace std;
long long m,n,d,e,kai;
int k;
int main()
{
	cin>>k;
    bool flag=0;
	while(k--){
		cin>>n>>d>>e;
        flag=0;
		m=n-d*e+2;
		for(int i=1;i<=min(m>>1ll,(long long)sqrt(n));++i){
            if(i*(m-i)==n){
                cout<<i<<' '<<m-i<<endl;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        else cout<<"NO"<<endl;
	}
	return 0;
}
