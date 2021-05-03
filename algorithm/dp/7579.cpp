#include <cstdio>
#include <algorithm>

using namespace std;

int memory[102], cost[102], dp[102][10004];

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) 
        scanf("%d", memory + i);
    for (int i = 1; i <= N; i++) 
        scanf("%d", cost + i);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 10000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
        }
    }
    for (int i = 1; i <= 10000; i++) {
        if (dp[N][i] >= M) {
            printf("%d", i);
            break;
        }
    }
}