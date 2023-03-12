#include<iostream>
#include<cstdio>
#include<cmath>
#define int long long//反正空间够，不开long long见祖宗，而且你必须开
using namespace std;
signed main()//因为define了int，所以要改成signed
{
	int T;
	cin>>T;
	for(int cishu=0;cishu<T;++cishu){
		int c,d;
		cin>>c>>d;
        c=abs(c);
        d=abs(d);
        if(c<d) swap(c,d);
        int ans=c+d+max(0ll,c-d-1);
        cout<<ans<<endl;
	}
	return 0;
}