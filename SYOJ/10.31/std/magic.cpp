#include<bits/stdc++.h>
#define For(i, j, k) for(int i = j; i <= k; ++i)
using namespace std;

inline int read() {
	int x = 0, p = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') p = -1; c = getchar(); }
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x *= p;
}

void File() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
}

const int N = 6e2 + 10, M = 1e7 + 10;
int prime[M], isnot[M], cnt, S[M], x;
int n, A[N], B[N], cnt1, cnt2, G[N][N];
int match[N], vis[N];

inline void Init(int n) {
	isnot[1] = 1;
	For(i, 2, n) {
		if(!isnot[i]) prime[++cnt] = i;
		For(j, 1, cnt) {
			if(1ll * i * prime[j] > n) break;
			isnot[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

inline bool dfs(int x) {
	For(i, 1, cnt2)	{
		if(G[x][i] && !vis[i]) {
			vis[i] = 1;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	File();
	Init(M - 5);
	n = read();
	For(i, 1, n) S[(x = read())] ^= 1;
	
	For(i, 1, M - 5) if(S[i] != S[i - 1]) {
		if(i & 1) A[++cnt1] = i;
		else B[++cnt2] = i;
	}
	For(i, 1, cnt1) For(j, 1, cnt2) 
		if(!isnot[abs(A[i] - B[j])]) G[i][j] = 1;	

	memset(match, -1, sizeof match);
	int res = 0, ans;
	For(i, 1, cnt1) {
		memset(vis, 0, sizeof vis);
		if(dfs(i)) ++ res;
	}

	ans = res + (cnt1 - res >> 1) * 2 + (cnt2 - res >> 1) * 2;
	if(cnt1 - res & 1) ans += 3;
	
	cout << ans << endl;
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}

