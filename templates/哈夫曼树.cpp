#include<iostream>
#include<cstdio>
using namespace std;
const long long MaxN=999999999999;
struct QHTree{
	long long weight;
	int parent;
	int lchild;
	int rchild;
};
QHTree ht[200005];
int n,k,ans;
void cht(){
	int lc,rc;
	long long minl,minr;
	for(int i=0;i<n;++i){
		cin>>ht[i].weight;
	}
	for(int i=0;i<2*n-1;++i){
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	}
	for(int i=n;i<2*n-1;++i){
		minl=minr=MaxN;
		lc=rc=-1;
		for(int j=0;j<i;++j){
			if(ht[j].parent==-1){
				if(ht[j].weight<minl){
					minr=minl;
					minl=ht[j].weight;
					rc=lc;
					lc=j;
				}
				else if(ht[j].weight<minr){
					minr=ht[j].weight;
					rc=j;
				}
			}
		}
		ht[lc].parent=ht[rc].parent=i;
		ht[i].weight=minl+minr;
		ht[i].lchild=lc;
		ht[i].rchild=rc;
		ans+=ht[i].weight;
	}
}
int main()
{
	cin>>n;
	cht();
	cout<<ans<<endl;
	return 0;
}