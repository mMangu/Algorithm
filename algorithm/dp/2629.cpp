#include <cstdio>

int weight[32];
bool dp[32][80004];
int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", weight + i);

    dp[0][40000] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 80000; j++) {
            if (!dp[i - 1][j]) continue;
            dp[i][j] = true;
            if (j + weight[i] <= 80000) dp[i][j + weight[i]] = true;
            if (j - weight[i] >= 0) dp[i][j - weight[i]] = true;
        }
    }
    int T; scanf("%d", &T);
    while (T--) {
        int input; scanf("%d", &input);
        if (dp[N][input + 40000]) printf("Y ");
        else printf("N ");
    }
}