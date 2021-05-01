#include <cstdio>
#include <vector>

using namespace std;

vector<int> v[100005];
bool check[100005];
int ans[100005];

void dfs(int n) {
    if (check[n]) return;
    check[n] = true;
    for (int i = 0; i < v[n].size(); i++) {
        if (!check[v[n][i]]) {
            ans[v[n][i]] = n;
            dfs(v[n][i]);
        }
    }
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int s, e; scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
        printf("%d\n", ans[i]);
}