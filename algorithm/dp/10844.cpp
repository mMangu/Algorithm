#include <cstdio>

using namespace std;
using ll = long long;
int mod = 1000000000;

int d[102][10];
int dp(int n, int s) {
    if (d[n][s]) return d[n][s]; 
    if (n == 0) return 0;
    if (n == 1 && s != 0) return 1;
    if (n == 1 && s == 0) return 0;
    if (s == 0) return d[n][s] = dp(n - 1, s + 1);
    if (s == 9) return d[n][s] = dp(n - 1, s - 1);
    return d[n][s] = (dp(n - 1, s - 1) + dp(n - 1, s + 1)) % mod;
}
int main() {
    int N; scanf("%d", &N);
    ll ans = 0;
    for (int i = 0; i <= 9; i++)
        ans = (ans + dp(N , i)) % mod;
    printf("%lld",ans % mod);
}