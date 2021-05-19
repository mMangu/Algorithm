#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dist[102][102], parent[102][102]; 
vector<int> v;

void trace(int s, int e) {
    if (!parent[s][e]) {
        v.push_back(s);
        v.push_back(e);
        return;
    }
    trace(s, parent[s][e]);
    v.pop_back();
    trace(parent[s][e], e);
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; i++) {
        int s, e, cost; scanf("%d %d %d", &s, &e, &cost);
        dist[s][e] = min(dist[s][e], cost);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                int newDist = dist[i][k] + dist[k][j];
                if (dist[i][j] > newDist) {
                    dist[i][j] = newDist;
                    parent[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", dist[i][j] == 1e9 ? 0 : dist[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == 1e9) printf("0\n");
            else {
                v.clear();
                trace(i, j);
                printf("%lu ", v.size());
                for (auto k : v) printf("%d ", k);
                printf("\n");
            }
        }
    }
}