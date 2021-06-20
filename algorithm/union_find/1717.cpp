#include <cstdio>
#include <algorithm>

int par[1000006], rank[1000006];
int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank[x] > rank[y]) std::swap(x, y);
    par[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        rank[i] = 1;
    }
    while (M--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (!a) merge(b, c);
        else find(b) == find(c) ? printf("YES\n") : printf("NO\n");
    }
}