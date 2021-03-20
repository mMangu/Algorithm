#define RED 1
#define BLUE 2
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> v[20004];
queue <int> q;
int check[200005], V, E;

void dfs (int start, int color) {
    if (color == RED) check[start] = BLUE;
    else check[start] = RED;
    for (int i = 0; i < v[start].size(); i++) {
        if (!check[v[start][i]]) {
            dfs(v[start][i], check[start]);
        }
    }
    return;
}

bool solve() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (check[i] == check[v[i][j]]) return false;
        }
    }
    return true;
}
int main() {
    int K; scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);
        bool flag = false;
        for (int i = 1; i <= V; i++) {
            check[i] = false;
            v[i].clear();
        }
        while (!q.empty()) q.pop();

        for (int i = 0; i < E; i++) {
            int a, b; scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= V; i++) {
            if (!check[i]) dfs(i, RED);
        }
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
}