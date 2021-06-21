#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool visited[1003];
vector<vector<int>> v;
int ans;

void dfs(int s) {
    visited[s] = true;
    ans++;
    for (auto i : v[s]) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, M; scanf("%d %d", &N, &M);
        v.clear(); v.resize(N + 1);
        memset(visited, false, sizeof(visited));
        while (M--) {
            int s, e; scanf("%d %d", &s, &e);
            v[s].push_back(e); v[e].push_back(s);
        }
        ans = 0;
        dfs(1);
        printf("%d\n", ans - 1);
    }
}