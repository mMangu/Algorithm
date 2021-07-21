#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int cnt[1003], dp[1003], cost[1003];

void solve() {
    memset(cnt, 0, sizeof cnt);
    memset(dp, 0, sizeof dp);
    memset(cost, 0, sizeof cost);
    int n, k; scanf("%d %d", &n, &k);
    vector<int> v[1003];
    for (int i = 1; i <= n; i++) scanf("%d", cost + i);
    for (int i = 0; i < k; i++) {
        int x, y; scanf("%d %d", &x, &y);
        v[x].push_back(y);
        cnt[y]++;
    }
    int to; scanf("%d", &to);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) q.push(i);
    }
    while (cnt[to] > 0) {
        int cur = q.front();
        q.pop();
        for (auto nxt : v[cur]) {
            dp[nxt] = max(dp[nxt], dp[cur] + cost[cur]);
            if (--cnt[nxt] == 0) q.push(nxt);
        }
    }
    printf("%d\n", dp[to] + cost[to]);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}