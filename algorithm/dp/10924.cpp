#include <cstdio>

bool dp[2003][2003];
int arr[2003];

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", arr + i);
    for (int i = 1; i <= N; i++) dp[i][i] = true;
    for (int i = 1; i <= N - 1; i++) dp[i][i + 1] = arr[i] == arr[i + 1];
    for (int i = 2; i < N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;
        }
    }
    int M; scanf("%d", &M);
    while (M--) {
        int s, e; scanf("%d %d", &s, &e);
        if (dp[s][e]) printf("1\n");
        else printf("0\n");
    }
}