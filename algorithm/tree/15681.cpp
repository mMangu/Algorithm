#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> v, child;
int sizeSubtree[100005];

void dpf(int node, int parent) {
    for (auto nxt : v[node]) {
        if (nxt != parent) {
            child[node].push_back(nxt);
            dpf(nxt, node);
        }
    }
}
void count(int cur) {
    sizeSubtree[cur] = 1;
    for (auto nxt : child[cur]) {
        count(nxt);
        sizeSubtree[cur] += sizeSubtree[nxt];
    }
}

int main() {
    int N, R, Q; scanf("%d %d %d", &N, &R, &Q);
    v.resize(N + 1);
    child.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b); v[b].push_back(a);
    }
    dpf(R, -1);
    count(R);
    while (Q--) {
        int ipt; scanf("%d", &ipt);
        printf("%d\n", sizeSubtree[ipt]);
    }
}