#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
vector<vector<int>> v, tree;
int cost[10004], dp[10004][2], visited[10004];

void dfs(int cur) {
    visited[cur] = true;
    for (auto nxt : v[cur]) {
        if (!visited[nxt]) {
            tree[cur].push_back(nxt);
            dfs(nxt);
        }
    }
}

int dpf(int cur, int great) {
    int &ret = dp[cur][great];
    if (ret != -1) return ret;
    int ans = 0;
    if (great) {
        for (auto nxt : tree[cur]) {
            ans += dpf(nxt, 0);
        }
        return ret = ans + cost[cur];
    } else {
        for (auto nxt : tree[cur]) {
            ans += max(dpf(nxt, 0), dpf(nxt, 1));
        }
        return ret = ans;
    }
}

int main() {
    int N; scanf("%d", &N);
    v.resize(N + 1); tree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", cost + i);
    }
    for (int i = 0; i < N; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    memset(dp, -1, sizeof(dp));
    printf("%d", max(dpf(1, 0), dpf(1, 1)));
}