#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
	int n,x=100,k=1,add=0;
	cin>>n;
	while(true){
		for(int i=0;i<7;i++){ //һ�ܳ�õ�Ǯ�� 
			add=add+x+i*k;
		}
		add*=52; //52���ܹ���õ�Ǯ�� 
		if(add!=n) { //���52���ܹ���õ�Ǯ��������n 
			x--; //x-1 
			if(x==0){
				x=x+100; //x���� 
				k++; //k+1 
			}
			add=0; //add���� 
		}
		else break; //���52���ܹ���õ�Ǯ������n������while����� 
	}
	cout<<x<<endl<<k;
	return 0;
}
