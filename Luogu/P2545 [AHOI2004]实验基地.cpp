#include <iostream>
using namespace std;
int a[2][2003];
int f[2003][2003];
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[1][i];
    //输入第一行
    for(int i=1;i<=n;++i) cin>>a[0][i];
    //输入第二行
    for(int i=1;i<n-1;++i){
        int cnt=0,mi=2147483640,sum=a[1][i+1]+a[1][i]+a[0][i]+a[0][i+1];
        //初始化cnt，赋值mi为一个极大值以便于之后min，初始化sum为最小的2x2的矩阵和
        for(int j=i+2;j<=n;++j){
            cnt=min(cnt,0);
            //尽量找带负数的
            cnt+=a[1][j-1];
            mi=min(mi,cnt);
            sum+=a[0][j]+a[1][j];
            ans=max(ans,sum-mi);
        }
    }
    cout<<ans;
    return 0;
}