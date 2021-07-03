#include <cstdio>
#include <cstring>

int d[22][22];
int dp[22][1 << 19];
int N;

int min(int a, int b) { return a > b ? b : a; }

int dpf(int cur, int state) {
    int &ret = dp[cur][state];
    if (state == (1 << N) - 1) return 0;
    if (ret != -1) return ret;
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        if ((state & (1 << i)) == 0) {
            ans = min(ans, dpf(cur + 1, state | (1 << i)) + d[cur][i]);
        }
    }
    return ret = ans;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &d[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d", dpf(0, 0));
}