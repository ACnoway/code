#include<iostream>
#include<cmath>
using namespace std;
int deng[2000001]={0};
int main()
{
	int n,t,b=0;
	cin>>n;
	for(int i=0;i<n;i++){
		double a;
		cin>>a>>t;
		for(int o=1;o<=t;o++){
			int c=floor(a*o);
			if(deng[c]==0) deng[c]=1;
			else deng[c]=0;
			b++;
		}
	}
	for(int i=0;i<b;i++){
		if(deng[i]==1){
			cout<<i; break;
		}
	}
 	return 0;
}

