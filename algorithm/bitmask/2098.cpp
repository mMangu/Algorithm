#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d[17][17], dp[17][1 << 16], N;

int dpf(int cur, int state) {
    int &ret = dp[cur][state];
    if (~ret) return ret;
    if (state == ((1 << N) - 1)) {
        if (d[cur][0] != 0) return d[cur][0];
        else return 1e9;
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i) || d[cur][i] == 0) continue; 
        ans = min(ans, dpf(i, state | (1 << i)) + d[cur][i]);
    }
    return ret = ans;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            scanf("%d", &d[i][j]);
    memset(dp, -1, sizeof(dp));
    int ans = dpf(0, 1);
    printf("%d\n", ans);
}