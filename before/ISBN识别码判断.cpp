#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int shu[10]={0,1,2,3,4,5,6,7,8,9},a1,b1,c1,d1,e1,f1,g1,h1,i1,sb1;
	int shuzi[10]={a1,b1,c1,d1,e1,f1,g1,h1,i1};
	char a,b,c,d,e,f,g,h,i,sb;
	scanf("%c%*c%c%c%c%*c%c%c%c%c%c%*c%c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&sb);
	char zi[58]={a,b,c,d,e,f,g,h,i};
	for(int x=0;x<9;x++) {
		for(int y=0;y<=9;y++){
			if(y+48==zi[x]) shuzi[x]=shu[y];
		}
	}
	int shibie=0;
	for(int z=0;z<9;z++){
		shibie+=shuzi[z]*(z+1);
	}
	shibie=shibie%11;
	for(int t=0;t<=9;t++){
		if(t+48==sb) sb1=t;
	}
	if(sb1==shibie||(shibie==10&&sb=='X')) cout<<"Right";
	else if(shibie==10) cout<<a<<"-"<<b<<c<<d<<"-"<<e<<f<<g<<h<<i<<"-"<<"X";
	else cout<<a<<"-"<<b<<c<<d<<"-"<<e<<f<<g<<h<<i<<"-"<<shibie;
	return 0;
 }
