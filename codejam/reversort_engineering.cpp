//틀림
#include <cstdio>

int arr[102];

void rever(int i, int j) {
    if (i > j) return;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    rever(i + 1, j - 1);
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, C; scanf("%d %d", &N, &C);
        if (C < N - 1 || C > 3 * N * (N - 1) / 2) {
            printf("Case #%d: IMPOSSIBLE\n", t);
            continue;
        }
        for (int i = 1; i <= N; i++) arr[i] = i;
        C = C - N + 1;
        for (int i = 1; i < N; i++) {
            if (C >= N - i) {
                rever(i, N);
                C = C - N + i;
            } else {
                rever(i, i + C);
                C = 0;
            }
        }
        printf("Case #%d: ", t);
        for (int i = 1; i <= N; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}