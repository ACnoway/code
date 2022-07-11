/**
 * @file P1681 最大正方形II.cpp
 * @author ACnoway (imlzhyt@163.com)
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
int a[1510][1510];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j) cin>>a[i][j];
    }
    return 0;
}