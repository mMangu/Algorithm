#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v, tree;
int dp[1000006][2];
bool visited[1000006];

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    for (auto nxt : v[cur]) {
        if (!visited[nxt]) {
            tree[cur].push_back(nxt);
            dfs(nxt);
        }
    }
}

int dpf(int cur, int include) {
    int &res = dp[cur][include];
    if (res != -1) return res;
    if (include) {
        int ans = 1;
        for (auto nxt : tree[cur]) {
            ans += min(dpf(nxt, 0), dpf(nxt, 1));
        }
        return res = ans;
    } else {
        int ans = 0;
        for (auto nxt : tree[cur]) {
            ans += dpf(nxt, 1);
        }
        return res = ans;
    }
}

int main() {
    int N; scanf("%d", &N);
    v.resize(N + 1);
    tree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b); v[b].push_back(a);
        dp[i][0] = dp[i][1] = -1;
    }
    dfs(1);
    printf("%d", min(dpf(1, 0), dpf(1, 1)));
}