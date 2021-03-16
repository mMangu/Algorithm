#define INF 2e9
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005], dp[100005], ans;
bool isAllminus;

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", arr + i);
        if (arr[i] > 0) isAllminus = true;
    }
    if (!isAllminus) {
        ans = -INF;
        for (int i = 1; i <= N; i++) ans = max(ans, arr[i]);
        printf("%d", ans);
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        if (dp[i - 1] + arr[i] > 0) dp[i] = dp[i - 1] + arr[i];
        else dp[i] = 0;
        ans = max(ans, dp[i]); 
    }
    printf("%d", ans);
}