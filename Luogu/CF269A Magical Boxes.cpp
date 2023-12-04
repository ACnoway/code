#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, ans = 0;
   ios::sync_with_stdio(0);
   cin >> n;
   for(int i = 0; i < n; ++i)
   {
      int a, b, x = 0; cin >> a >> b;
      while((1<<x) < b) ++x;
      ans = max(ans, max(1,(x+1)>>1)+a);
   }
   cout << ans << '\n';
   return 0;
}
