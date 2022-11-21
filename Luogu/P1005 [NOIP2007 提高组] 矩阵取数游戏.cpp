#include<iostream>
using namespace std;
int a[100][100];
int n,m;
int l[100],r[100];
void write(__int128_t x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) cin>>a[i][j];
		l[i]=1;
		r[i]=m;
	}
	__int128_t ans=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(a[j][l[j]]<a[j][r[j]]){
				ans+=a[j][l[j]]*(1<<i);
				l[j]++;
			}
			else{
				ans+=a[j][r[j]]*(1<<i);
				r[j]--;
			}
		}
	}
	write(ans);
	return 0;
}
