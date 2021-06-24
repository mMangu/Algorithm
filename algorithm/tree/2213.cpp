#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int cost[10004], dp[10004][2], check[10004], res;
vector<vector<int>> v, tree;
vector<int> ansarr;

void dfs(int cur, int prv) {
    for (auto nxt : v[cur]) {
        if (nxt != prv) {
            tree[cur].push_back(nxt);
            dfs(nxt, cur);
        }
    }
}

int dpf(int cur, bool include) {
    int &res = dp[cur][include];
    if (res != -1) return res;

    if (include) {
        int ans = 0;
        for (auto nxt : tree[cur]) ans += dpf(nxt, 0);
        return res = ans + cost[cur];
    } else {
        int ans = 0;
        for (auto nxt : tree[cur]) {
            int t1 = dpf(nxt, 0);
            int t2 = dpf(nxt, 1);
            if (t1 < t2) check[nxt] = 1;
            else check[nxt] = 0;
            ans += max(t1, t2);
        }
        return res = ans;
    }
}

void track(int cur, int include) {
    if (include) {
        ansarr.push_back(cur);
        for (auto nxt : tree[cur]) track(nxt, 0);
    } else {
        for (auto nxt : tree[cur]) track(nxt, check[nxt]);        
    }
}

int main() {
    int N; scanf("%d", &N);
    v.resize(N + 1);
    tree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", cost + i);
        dp[i][0] = dp[i][1] = -1;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b); v[b].push_back(a);
    }

    dfs(1, 1);
    int t1 = dpf(1, 0);
    int t2 = dpf(1, 1);
    if (t1 < t2) check[1] = 1;
    else check[1] = 0;
    printf("%d\n", max(t1, t2));

    track(1, check[1]);
    sort(ansarr.begin(), ansarr.end());
    for (auto iter : ansarr) printf("%d ", iter);
}