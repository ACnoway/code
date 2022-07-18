#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c,duan1,duan2,chang;
	cin>>a>>b>>c;
	if(!((a+b)>c&&(a+c)>b&&(b+c)>a)){
		cout<<"Not triangle"; return 0;
	}
	else{
		if(a>=b&&a>=c){
			chang=a;duan1=b;duan2=c;
		}
		if(b>=a&&b>=c){
			chang=b;duan1=a;duan2=c;
		}
		if(c>=b&&c>=a){
			chang=c;duan1=b;duan2=a;
		}
		if(pow(duan1,2)+pow(duan2,2)==pow(chang,2)) cout<<"Right triangle"<<endl;
		if(pow(duan1,2)+pow(duan2,2)>pow(chang,2)) cout<<"Acute triangle"<<endl;
		if(pow(duan1,2)+pow(duan2,2)<pow(chang,2)) cout<<"Obtuse triangle"<<endl;
		if(chang==duan1||chang==duan2||duan1==duan2) cout<<"Isosceles triangle"<<endl;
		if(chang==duan1&&chang==duan2) cout<<"Equilateral triangle"<<endl;
	}
	
	return 0;
}


