#include <cstdio>
#include <stack>

using namespace std;

int arr[1003], dp[1003], ans, check;
stack<int> s;

int max(int a, int b) { return a > b ? a : b; }
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j]) cnt = max(cnt, dp[j]);
        dp[i] = ++cnt;
        if (ans < dp[i]) {
            ans = dp[i];
            check = i;
        }
    }
    // for (int i = 0; i < N; i++) printf("%d ", dp[i]);
    printf("%d\n", ans);
    for (int i = check; i >= 0; i--) {
        if (ans && dp[i] == ans) {
            s.push(arr[i]);
            ans--;
        }
    }
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
}