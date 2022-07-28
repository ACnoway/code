#include<iostream>
using namespace std;
int main()
{
	int mo1,mo2,tu1,tu2,we1,we2,th1,th2,fr1,fr2,sa1,sa2,su1,su2,zui=0,zuida=0;
	cin>>mo1>>mo2>>tu1>>tu2>>we1>>we2>>th1>>th2>>fr1>>fr2>>sa1>>sa2>>su1>>su2;
	int mo=mo1+mo2,tu=tu1+tu2,we=we1+we2,th=th1+th2,fr=fr1+fr2,sa=sa1+sa2,su=su1+su2;
	if(mo>zuida&&mo>=8){
		zuida=mo;
		zui=1;
	} 
	if(tu>zuida&&tu>=8){
		zuida=tu;
		zui=2;
	}
	if(we>zuida&&we>=8){
		zuida=we;
		zui=3;
	}
	if(th>zuida&&th>=8){
		zuida=th;
		zui=4;
	}
	if(fr>zuida&&fr>=8){
		zuida=fr;
		zui=5;
	}
	if(sa>zuida&&sa>=8){
		zuida=sa;
		zui=6;
	}
	if(su>zuida&&su>=8){
		zuida=su;
		zui=7;
	}
	cout<<zui;
	return 0;
 } 
