#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1003], dp[1003], check, ans;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", arr + i);
    check = arr[0];
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        int MAX = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) MAX = max(MAX, dp[j]);
        }
        dp[i] = MAX + 1;
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
}