#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second 
const int N = 505;
typedef pair<int, int> PII;
int s[N][N];
int n, m, k;
int res;
vector<PII> state;

bool cmp(PII a, PII b){
    if(a.x > b.x) return false;
    else{
        if(a.x < b.x) return true;
        else if(a.x == b.x) return a.y < b.y;
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &s[i][j]);
            if(s[i][j] <= k) res ++;
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            state.push_back({i, j});
        }
    }
    sort(state.begin(), state.end());
    for(int i = 0; i < state.size(); i ++){
        for(int j = i + 1; j < state.size(); j ++){
            int x1 = state[i].x, y1 = state[i].y, x2 = state[j].x, y2 = state[j].y;
            if(x1 <= x2 && y1 <= y2){
                int sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
                if(sum <= k) res ++;
                else break;
            }
        }
    }
    cout << res;
    return 0;
}