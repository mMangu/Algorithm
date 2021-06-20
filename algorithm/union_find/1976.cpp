#include <cstdio>
#include <algorithm>

int par[202], rank[202];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;

    if (rank[x] < rank[y]) std::swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        rank[i] = 1;        
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int ipt; scanf("%d", &ipt);
            if (ipt) {
                int a = find(i), b = find(j);
                if (a == b) continue;
                merge(a, b);
            }
        }
    }
    int root;
    bool flag = true;
    for (int i = 0; i < M; i++) {
        int goal; scanf("%d", &goal);
        if (!i) root = find(goal);
        else if (root != find(goal)) flag = false;
    }
    printf("%s", flag ? "YES" : "NO");
}