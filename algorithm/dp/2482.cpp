#include <bits/stdc++.h>

using namespace std;

int dp[1003][1003];
int n, k;
const int mod = 1e9 + 3;

int dpf(int cur, int cnt) {
    int &ret = dp[cur][cnt];
    //cnt가 1이면 남은 것중에 아무거나 하나만 칠하면 됨
    if (cnt == 1) return cur;
    //cur이 2 * cnt보다 작으면 인접하는 경우가 무조건 한개 이상 나옴
    if (cur <= 0 || cur < 2 * cnt) return 0;
    if (~ret) return ret;
    return ret = (dpf(cur - 2, cnt - 1) + dpf(cur - 1, cnt)) % mod;
}

int main() {
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof(dp));    
    printf("%d", dpf(n, k));
}