#include <iostream>
#include <utility>
#include <cstdio>
using namespace std;
inline string reads(){
    string s;
    char c=getchar();
    while(c<'A'||c>'Z'){
        c=getchar();
    }
    while(c>='A'&&c<='Z'){
        s+=c;
        c=getchar();
    }
    return s;
}
inline int read(){
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
pair<string,int> a[100005];
int n,m;
int calc(int bit,int v){
    //用初始攻击力的第k位与每一个防御门的第k位进行计算
    //算出最后的结果
    for(int i=1;i<=n;++i){
        //取出第k位
        int x=a[i].second>>bit&1;
        switch (a[i].first[0]){
            case 'A':{
                v&=x;
                break;
            }
            case 'O':{
                v|=x;
                break;
            }
            default:{
                v^=x;
                break;
            }
        }
    }
    return v;
}
//因为位运算不进位，所以我们可以单独处理每一二进制位
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i].first=reads();
        a[i].second=read();
    }
    int ans=0,v=0;
    //v是初始攻击力
    //ans是最终攻击力
    for(int k=29;k>=0;--k){
        int r0=calc(k,0);
        int r1=calc(k,1);
        if(v+(1<<k)<=m&&r0<r1){
            //在不超过m的情况下
            //如果初始攻击力的第k位填1
            //比填0的收益更高（最终攻击力更高）
            v+=1<<k;
            ans+=1<<k;
        }
        else{
            //要不然就填0，因为是0所以
            //初始攻击力不变，要将最终攻击力
            //更新为填0的收益，因为有可能是1所以要更新
            ans+=r0<<k;
            cout<<r0<<endl;
        }
    }
    write(ans);
    return 0;
}