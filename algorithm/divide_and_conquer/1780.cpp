#include <cstdio>

int map[2200][2200], cnt0, cnt1 ,cnt_1;

void solve(int y, int x, int N) {
    int tmp0 = 0, tmp1 = 0, tmp_1 = 0;
    for (int i = y; i < y + N; i++) {
        for (int j = x; j < x + N; j++) {
            if (map[i][j] == 0) tmp0++;
            else if (map[i][j] == 1) tmp1++;
            else tmp_1++;
        }
    }
    if (tmp0 == N * N) {
        cnt0++;
        return;
    } else if (tmp1 == N * N) {
        cnt1++;
        return;
    } else if (tmp_1 == N * N) {
        cnt_1++;
        return;
    }
    int next = N / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(y + next * i, x + next * j, next);
        }
    }
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    solve(0, 0, N);
    printf("%d\n%d\n%d", cnt_1, cnt0, cnt1);
}