#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
//#include <bits/stdc++.h>
using namespace std;
int mapi[1000005][20],mapa[1000005][20];
int n;
void work()
{
    int i,j;
    for(j=1;1<<j<=n;j++)
        for(i=1;i+(1<<j)-1<=n;i++){//i+(1<<j)-1<=n是为了保证区间左端点不超出总数n
            mapi[i][j]=min(mapi[i][j-1],mapi[i+(1<<j-1)][j-1]);//实质是动态规划
            mapa[i][j]=max(mapa[i][j-1],mapa[i+(1<<j-1)][j-1]);
        }
}
int qmin(int z,int y)
{
    int x=int (log(y-z+1)/log(2));//注意y-z要加一才为区间长度
    return min(mapi[z][x],mapi[y-(1<<x)+1][x]);//分别以左右两个端点为基础，向区间内跳1<<x的最
//大值; 
}
int qmax(int z,int y)
{
    int x=int (log(y-z+1)/log(2));//注意y-z要加一才为区间长度
    return max(mapa[z][x],mapa[y-(1<<x)+1][x]);//分别以左右两个端点为基础，向区间内跳1<<x的最
//大值; 
}
int main()
{
    scanf("%d",&n);//输入数据总数
    int i,a,b,k;
    for(i=1;i<=n;i++){
        scanf("%d",&mapi[i][0]);//数据输入加初始化，即从i开始向右走2的0次方的区间中的最大值，（注//意i到i的长度为一）。
        mapa[i][0]=mapi[i][0];
    }
    work();//预处理
    scanf("%d",&k);//输入询问次数k
    for(i=1;i<=k;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d %d\n",qmin(a,b),qmax(a,b));//输出结果
        }
    return 0;
}