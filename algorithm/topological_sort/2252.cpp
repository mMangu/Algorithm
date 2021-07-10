#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int cnt[32003];

int main() {
    int N, M; scanf("%d %d", &N, &M);
    vector<vector<int>> v(N + 1);
    while (M--) {
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b);
        cnt[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!cnt[i]) q.push(i);
    }
    for (int i = 0; i < N; i++) {
        int cur = q.front();
        printf("%d ", cur);
        q.pop();
        for (auto nxt : v[cur]) {
            cnt[nxt]--;
            if (!cnt[nxt]) q.push(nxt);
        }
    }
}