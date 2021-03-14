#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10004], dp[10004];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }
    printf("%d", dp[n]);
}