#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int result[1001]={1,1},base[1001]={1,2};
void mul1(){
	int temp[1001]={0};
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			temp[i+j-1]+=result[i]*base[j];
		}
	}
	for(int i=1;i<=500;i++){
		temp[i+1]+=temp[i]/10;
		temp[i]%=10;
	}
	memcpy(result,temp,sizeof(result));
}
void mul2(){
	int temp[1001]={0};
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			temp[i+j-1]+=base[i]*base[j];
		}
	}
	for(int i=1;i<=500;i++){
		temp[i+1]+=temp[i]/10;
		temp[i]%=10;
	}
	memcpy(base,temp,sizeof(base));
}
void fastPower(int base[],int power){
    while (power!=0) {
        if (power & 1) {//此处等价于if(power%2==1)
            mul1();
        }
        power >>= 1;//此处等价于power=power/2
        mul2();
    }
}
int main()
{
	int p;
	cin>>p;
	cout<<(int)(log10(2)*p+1)<<endl;
	fastPower(base,p);
	result[1]-=1;
	for(int i=500;i>=1;i--){
		if(i!=500&&i%50==0){
			cout<<endl;
		}
		cout<<result[i];
	}
	return 0;
}

