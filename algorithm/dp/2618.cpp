#include <cstdio>
#include <algorithm>
#include <cstring>
#define x first
#define y second

using namespace std;
using pii = pair<int, int>;

int dp[1003][1003], N, W;
pii arr[1003];

int dist(pii a, pii b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int dpf(int i, int j) {
    if (i == W || j == W) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int next = max(i, j) + 1, dist1, dist2;

    if (i == 0) dist1 = dist(pii(1, 1), arr[next]);
    else dist1 = dist(arr[i], arr[next]);

    if (j == 0) dist2 = dist(pii(N, N), arr[next]);
    else dist2 = dist(arr[j], arr[next]);

    dp[i][j] = min(dpf(next, j) + dist1, dpf(i, next) + dist2);
    return dp[i][j];
}

void trace(int i, int j) {
    if (i == W || j == W) return;
    int next = max(i, j) + 1, dist1, dist2;

    if (i == 0) dist1 = dist(pii(1, 1), arr[next]);
    else dist1 = dist(arr[i], arr[next]);

    if (j == 0) dist2 = dist(pii(N, N), arr[next]);
    else dist2 = dist(arr[j], arr[next]);

    if (dp[next][j] + dist1 < dp[i][next] + dist2) {
        printf("1\n");
        trace(next, j);
    } else {
        printf("2\n");
        trace(i, next);
    } 
}

int main() {
    scanf("%d %d", &N, &W);
    for (int i = 1; i <= W; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dpf(0, 0));
    // for (int i = 0; i <= W; i++)
    //     for (int j = 0; j <= W; j++)
    //         printf("(%d, %d) = %d\n", i, j, dp[i][j]);
    trace(0, 0);
}