#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int dp[102][100005], ans;
pair <int, int> arr[102];

int main() {
    int N, K; scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K ; j++) {
            dp[i][j] = dp[i -1][j];
            if (j - arr[i].first >= 0) 
                dp[i][j] = max(dp[i][j], dp[i -1][j - arr[i].first] + arr[i].second);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }

    printf("%d", dp[N][K]);
}
