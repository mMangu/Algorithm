#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> arr[502];
int dp[502][502];

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    for (int i = 1; i < N; i++) {
        dp[i][i + 1] = arr[i].first * arr[i].second * arr[i + 1].second;
    }
    for (int m = 2; m <= N; m++) {
        for (int i = 1; i <= N - m; i++) {
            int j = i + m;
            for (int k = i; k < j; k++) {
                int res = dp[i][k] + dp[k + 1][j] + arr[i].first * arr[k].second * arr[j].second;
                if (!dp[i][j] || dp[i][j] > res) dp[i][j] = res;
            }
        }
    }
    printf("%d", dp[1][N]);
}