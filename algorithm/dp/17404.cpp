#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1002][3];
int dp[1002][3];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < 3; j++) 
            scanf("%d", &arr[i][j]);

    int ans = 1e9;
    for (int k = 0; k < 3; k++) {
        for (int i = 1; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
            // 첫번째 색을 고정시킨다
            if (i == 1) {
                for (int j = 0; j < 3; j++) if (j != k) dp[i][j] = 1e9;
            }
            // n번째에 첫번째와 색이 같은 경우를 배제시킨다.
            if (i == n) dp[i][k] = 1e9;
        }
        ans = min(ans, min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
    printf("%d", ans);
}