#include <bits/stdc++.h>

using namespace std;

int dp[1003][1003];
int n, k;
const int mod = 1e9 + 3;

int dpf(int cur, int cnt) {
    int &ret = dp[cur][cnt];
    if (cnt == 1) return cur;
    if (cur <= 0 || cur < 2 * cnt) return 0;
    if (~ret) return ret;
    return ret = (dpf(cur - 2, cnt - 1) + dpf(cur - 1, cnt)) % mod;
}

int main() {
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof(dp));    
    printf("%d", dpf(n, k));
}