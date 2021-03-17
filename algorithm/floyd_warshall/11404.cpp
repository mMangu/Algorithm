#include <cstdio>
#include <algorithm>

const int INF = 1e9;
int cost[102][102];

int main() {
    int N, M; scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if(i != j) cost[i][j] = INF;
    
    for (int i = 0; i < M; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = std::min(c, cost[a][b]); 
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cost[i][j] >= INF) printf("0 ");
            else printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}