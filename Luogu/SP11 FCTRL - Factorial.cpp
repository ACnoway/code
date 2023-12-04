#include<bits/stdc++.h>
int main() {
    int n;
    scanf("%d",&n); //共n个数字
    while(n--) {
        int t,ans=0,tmp=5;
        //t: 当前数字; ans: 当前结果; tmp: 后面有解释
        scanf("%d",&t);
        //当t/tmp≤0时，后面再怎么计算结果都不会变了，所以循环可以终止了
        while(t/tmp>0) ans+=t/tmp,tmp*=5; //第n次循环tmp就是5^n
        printf("%d\n",ans); //输出当前结果
    }
    return 0;
}
