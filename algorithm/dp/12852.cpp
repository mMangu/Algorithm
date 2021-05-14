#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

pii dp[1000006];

void solve(int N) {
    if (N < 1) return;
    if (N % 3 == 0 && dp[N / 3].first > dp[N].first + 1) {
        dp[N / 3].first = dp[N].first + 1;
        dp[N / 3].second = N;
        solve(N / 3);
    }
    if (N % 2 == 0 && dp[N / 2].first > dp[N].first + 1) {
        dp[N / 2].first = dp[N].first + 1;
        dp[N / 2].second = N;
        solve(N / 2);
    }
    if (N > 1 && dp[N - 1].first > dp[N].first + 1) {
        dp[N - 1].first = dp[N].first + 1;
        dp[N - 1].second = N; 
        solve(N - 1);
    }
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) dp[i].first = 2e9;
    dp[N].first = 0;
    solve(N);
    printf("%d\n", dp[1].first);
    int cur = 1;
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < dp[1].first; i++) {
        v.push_back(dp[cur].second);
        cur = dp[cur].second;
    }
    for (int i = v.size() - 1; i >= 0; i--)
        printf("%d ", v[i]);
}