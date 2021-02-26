#include <cstdio>
int input[12];
int main() {
    int ans = 0;
    int N, K; scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d",input + i);
    for (int i = N; i > 0 ; i--) {
        if (K >= input[i]) {
            int divide = K / input[i];
            K = K - (input[i] * divide);
            ans = ans + divide;
        }
        if (K == 0) break;
    }
    printf("%d",ans);
}