#include<iostream>
using namespace std;
int t;
int f[10000007],nx[10000007];
//判断一个数是否含7
bool check(int x){
    while(x){
        if(x%10==7) return 1;
        x/=10;
    }
    return 0;
}
void init(){
    //当前要找下一个的数
    int ls=0;
    for(int i=1;i<=10000005;++i){
        if(f[i]) continue;
        else if(check(i)){
            //跟埃氏筛差不多，更新它的倍数
            for(int j=i;j<=10000005;j+=i){
                f[j]=1;
            }
        }
        else{
            //记录要选的下一个
            nx[ls]=i;
            ls=i;
        }
    }
}
int main()
{
    cin>>t;
    init();
    while(t--){
        int x;
        cin>>x;
        if(f[x]){
            cout<<"-1"<<endl;
        }
        else cout<<nx[x]<<endl;
    }
    return 0;
}