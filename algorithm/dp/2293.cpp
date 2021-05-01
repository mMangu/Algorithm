#include <cstdio>

int arr[102], dp[10004];

int main() {
    int N, K; scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }
    
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= arr[i]) dp[j] += dp[j - arr[i]];
        }
    }

    printf("%d", dp[K]);
}