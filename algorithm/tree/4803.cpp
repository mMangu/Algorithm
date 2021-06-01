#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool visited[502];

bool dfs(int cur, int par, vector<int> v[]) {
    visited[cur] = true;

    for (auto iter : v[cur]) {
        if (iter == par) continue;
        if (visited[iter]) return false;
        if (!dfs(iter, cur, v)) return false;
    }
    return true;
}

int main() {
    int cnt = 1;
    while (true) {
        int n, m; scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) return 0;
        memset(visited, 0, sizeof(visited));
        vector<int> v[n + 1];
        while (m--) {
            int s, e; scanf("%d %d", &s, &e);
            v[s].push_back(e);
            v[e].push_back(s);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                if (dfs(i, 0, v)) ans++;
        }
        printf("Case %d", cnt);
        cnt++;
        if (!ans) printf(": No trees.");
        else if (ans == 1) printf(": There is one tree.");
        else printf(": A forest of %d trees.", ans);
        printf("\n");
    }
}