#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=102;
int n,k;
struct Mat{
	int a[N][N];
	Mat(){
		for(int i=0;i<N;++i) for(int j=0;j<N;++j) a[i][j]=0;
	}
	Mat operator *(const Mat x)const{
		Mat res;
		
	}
};
signed main()
{
	
	return 0;
}
