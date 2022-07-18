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
		int a=1,b=1,c,d;
		cin>>c>>d;
        if (c==1&&d!=1){
            cout<<"-1\n";
            continue;
        }
		int ac=abs(a-c),bd=abs(b-d);
		int temp=ac,ans=min(ac,bd);
       //哪边小把哪边当做正方形的底，要不然就把点cd越过去了
		ac-=min(temp,bd);//求需要直走的长度
        bd-=min(temp,bd);
		int bigger=max(ac,bd);
		if(bigger&1) cout<<(ans*2+bigger*2-1);
      //位运算判断奇偶更快
		else cout<<(ans*2+bigger*2);
		cout<<endl;
	}
	return 0;
}