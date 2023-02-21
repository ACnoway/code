#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int st=0,lft=26,cnt[26];
int main()
{
    freopen("str.in","r",stdin);
    freopen("str.out","w",stdout);
    ios::sync_with_stdio(false);
    string a;
    cin>>a;
    int n=a.size(),ans=n+1;
    for(int i=0;i<n;++i){
        if(cnt[a[i]-'A']==0){
            lft--;
        }
        cnt[a[i]-'A']++;
        if(!lft){
            for(;st<n;++st){
                if(cnt[a[st]-'A']==1) break;
                else cnt[a[st]-'A']--;
            }
            ans=min(ans,i-st+1);
        }
    }
    if(ans!=n+1) cout<<ans<<endl;
    else cout<<"QwQ"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}