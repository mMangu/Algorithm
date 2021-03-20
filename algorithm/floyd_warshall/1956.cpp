#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
int dist[402][402];

int main() {
    int V, E; scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            dist[i][j] = 1e9;
    for (int i = 0; i < E; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
    }
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }
    if (ans >= 1e9) printf("-1");
    else printf("%d", ans);
}