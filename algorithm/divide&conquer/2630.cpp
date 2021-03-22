#include <cstdio>

int a[130][130];
int blue = 0, white = 0;
void solve(int y, int x, int N) {
    int cnt = 0;
    for (int i = y; i < y + N; i++) {
        for (int j = x; j < x + N; j++) {
            if (a[i][j]) cnt++;
        }
    }
    if (cnt == N * N) {
        blue++;
        return;    
    } else if (!cnt) {
        white++;
        return;
    }
    solve(y, x , N / 2);
    solve(y + N / 2, x, N / 2);
    solve(y, x + N / 2, N / 2);
    solve(y + N / 2, x + N / 2, N / 2);
    return;
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    solve(1, 1, N);
    printf("%d\n%d", white, blue);
}