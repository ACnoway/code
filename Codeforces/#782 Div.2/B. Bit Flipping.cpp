#include <iostream>
#include <cstdio>
using namespace std;
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
int t,n,k,sum;
int cnt[200005];
string s;
int main()
{
    cin>>t;
    while(t--){
        sum=0;
        for(int i=0;i<200002;++i) cnt[i]=0;
        cin>>n>>k>>s;
        int temp=k;
        for(int i=0;i<n;++i){
            //cout<<"i: "<<i<<" k: "<<k<<" s[i]: "<<s[i]<<endl;
            if(s[i]=='0'){
                if(temp-k&1){
                    if(k&1){
                        k--;
                        cnt[i]++;
                        if(k<=0) break;
                    }
                }
                else{
                    if(k&1){
                        k--;
                        cnt[n-1]++;
                        if(k<=0) break;
                    }
                    else{
                        k--;
                        cnt[i]++;
                        if(k<=0) break;
                        k--;
                        cnt[n-1]++;
                        if(k<=0) break;
                    }
                }
            }
            else{
                if(k&1){
                    k--;
                    cnt[i]++;
                    if(k<=0) break;
                }
            }
            if(k<=0) break;
        }
        cnt[0]+=k;
        k=temp;
        for(int i=0;i<n;++i){
            if((k-cnt[i])&1){
                //cout<<k-cnt[i]<<endl;
                s[i]=!(s[i]-48)+48;
            }
            putchar(s[i]);
        }
        putchar('\n');
        for(int i=0;i<n;++i){
            write(cnt[i]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}