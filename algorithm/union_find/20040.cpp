#include <cstdio>
#include <algorithm>

using namespace std;

int par[500005], level[500005];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return;
    if (level[a] > level[b]) swap(a, b);
    if (level[a] == level[b]) level[b]++;
    par[a] = b;
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++) {
        par[i] = i;
        level[i] = 1;
    }
    for (int i = 1; i <= M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        int x = find(a), y = find(b);
        if (x != y) merge(x, y);
        else { printf("%d", i); return 0; }
    }
    printf("0");
}