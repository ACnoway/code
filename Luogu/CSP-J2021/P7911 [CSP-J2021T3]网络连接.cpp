#include<iostream>
#include<cstdio>
#include<sstream>
#define int long long
using namespace std;
string ser[1001];
int serp[1001];
signed main()
{
	ios::sync_with_stdio(false);
	int n,scnt=0;
	cin>>n;
	for(int t=1;t<=n;++t){
		string op,ad;
		cin>>op>>ad;
		int a=-1,b=-1,c=-1,d=-1,e=-1;
		int i=0;
		int dian=0,mao=0;
		for(int j=0;j<ad.size();++j){
			if(ad[j]=='.'&&mao==0){
				dian++;
				continue;
			}
			else if(ad[j]=='.'){
				dian=0;mao=0;
				break;
			}
			if(ad[j]==':'&&dian==3){
				mao++;
				continue;
			}
			else if(ad[j]==':'){
				dian=0;mao=0;
				break;
			}
		}
		if(dian!=3||mao!=1){
			cout<<"ERR"<<endl;
			continue;
		}
		if(ad[i]=='0'&&i+1<ad.size()){
			if(ad[i+1]>='0'&&ad[i+1]<='9'){
				cout<<"ERR"<<endl;
				continue;
			}
		}
		for(;ad[i]!='.'&&i<ad.size();++i){
			if(a==-1) a=0;
			a=(a<<1)+(a<<3)+(ad[i]^48);
		}
		i++;
		if(i<ad.size())
		if(ad[i]=='0'&&i+1<ad.size()){
			if(ad[i+1]>='0'&&ad[i+1]<='9'){
				cout<<"ERR"<<endl;
				continue;
			}
		}
		for(;ad[i]!='.'&&i<ad.size();++i){
			if(b==-1) b=0;
			b=(b<<1)+(b<<3)+(ad[i]^48);
		}
		i++;
		if(i<ad.size())
		if(ad[i]=='0'&&i+1<ad.size()){
			if(ad[i+1]>='0'&&ad[i+1]<='9'){
				cout<<"ERR"<<endl;
				continue;
			}
		}
		for(;ad[i]!='.'&&i<ad.size();++i){
			if(c==-1) c=0;
			c=(c<<1)+(c<<3)+(ad[i]^48);
		}
		i++;
		if(i<ad.size())
		if(ad[i]=='0'&&i+1<ad.size()){
			if(ad[i+1]>='0'&&ad[i+1]<='9'){
				cout<<"ERR"<<endl;
				continue;
			}
		}
		for(;ad[i]!=':'&&i<ad.size();++i){
			if(d==-1) d=0;
			d=(d<<1)+(d<<3)+(ad[i]^48);
		}
		i++;
		if(i<ad.size())
		if(ad[i]=='0'&&i+1<ad.size()){
			if(ad[i+1]>='0'&&ad[i+1]<='9'){
				cout<<"ERR"<<endl;
				continue;
			}
		}
		for(;i<ad.size();++i){
			if(e==-1) e=0;
			e=(e<<1)+(e<<3)+(ad[i]^48);
		}
		//cout<<ad<<endl<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
		if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255||e<0||e>65535){
			cout<<"ERR"<<endl;
			continue;
		}
		bool flag=true;
		if(op=="Server"){
			for(int i=0;i<scnt;++i){
				if(ser[i]==ad){
					flag=false;
					break;
				}
			}
			if(flag){
				ser[scnt]=ad;
				serp[scnt++]=t;
				cout<<"OK"<<endl;
				continue;
			}
			else{
				cout<<"FAIL"<<endl;
				continue;
			}
		}
		else{
			for(int i=0;i<scnt;++i){
				if(ser[i]==ad){
					cout<<serp[i]<<endl;
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<"FAIL"<<endl;
				continue;
			}
		}
	}
	return 0;
}