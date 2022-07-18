#include<iostream>
using namespace std;
int main()
{
	int n,x,t=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		if(i%10==x) t+=1;
		if(i>9){
			if(i/10%10==x) t+=1;
			if(i>99){
				if(i/100%10==x) t+=1;
				if(i>999){
					if(i/1000%10==x) t+=1;
					if(i>9999){
						if(i/10000%10==x) t+=1;
						if(i>99999){
							if(i/100000%10==x) t+=1;
							if(i>999999){
								if(i/1000000==x) t+=1;
							}
						}
					}
				}
			}			
		}
		
	}
	cout<<t;
	return 0;
} 
