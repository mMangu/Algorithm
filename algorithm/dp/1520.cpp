#include <cstdio>

int map[502][502], dp[502][502], N, M;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int y, int x) {
    if (y == M - 1 && x == N - 1) return 1;
    if (dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if (map[y][x] > map[ny][nx]) dp[y][x] += dfs(ny, nx);
        }
    }
    return dp[y][x];
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) { 
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    int ans = dfs(0, 0);
    printf("%d", ans);
}