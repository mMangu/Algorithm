#include <cstdio>
#include <algorithm>

using namespace std;

int dp[502][502], cost[502], sum[502];
const int INF = 1e9;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int K; scanf("%d", &K);
        for (int i = 1; i <= K; i++) {
            scanf("%d", cost + i);
            sum[i] = sum[i - 1] + cost[i];
        }
        for (int d = 1; d < K; d++) {
            for (int x = 1; x + d <= K; x++) {
                int y = x + d;
                dp[x][y] = INF;
                for (int mid = x; mid < y; mid++)
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
            }
        }
        printf("%d\n", dp[1][K]);
    }
}