#include <cstdio>

int weight[32], N;
bool dp[32][80004];

void solve(int i, int j) {
    if (dp[i][j]) return;
    if (i == N) {
        dp[i][j] = true;
        return;
    } 
    dp[i][j] = true;
    solve(i + 1, j + weight[i + 1]);
    solve(i + 1, j - weight[i + 1]);
    solve(i + 1, j);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", weight + i);
    int M; scanf("%d", &M);
    solve(0, 40000);
    while (M--) {
        int input; scanf("%d", &input);
        printf("%c ", dp[N][input + 40000] ? 'Y' : 'N');
    }
}