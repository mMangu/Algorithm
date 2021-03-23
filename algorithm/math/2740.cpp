#include <cstdio>

int N, M, K;
int A[102][102], B[102][102], ans[102][102];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0 ; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);
    scanf("%d %d", &M, &K);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            scanf("%d", &B[i][j]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int t = 0; t < M; t++) {
                ans[i][j] += A[i][t] * B[t][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}