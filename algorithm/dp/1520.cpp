//dfs TLE 코드
#include <cstdio>

int map[502][502], N, M, ans;

void dfs(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N) return;
    if (i == M - 1 && j == N - 1) {
        ans++;
        return;
    }
    if (map[i][j] > map[i][j + 1]) dfs(i, j + 1);
    if (map[i][j] > map[i + 1][j]) dfs(i + 1, j);
    if (map[i][j] > map[i][j - 1]) dfs(i, j - 1);
    if (map[i][j] > map[i - 1][j]) dfs(i - 1, j);
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++) 
            scanf("%d", &map[i][j]);
    dfs(0, 0);
    printf("%d", ans);
}