#include <cstdio>

using ll = long long;

bool check[1000006];

int main() {
    ll m, M; scanf("%lld %lld", &m, &M);
    for (ll i = 2; i * i <= M; i++) {
        ll start = m / (i * i);
        if (start * i * i != m) start++;
        for (ll j = start; i * i * j <= M; j++) {
            check[i * i * j - m] = true;
        }
    }
    int ans = 0;
    for (ll i = 0; i <= M - m; i++) {
        if(!check[i]) ans++;
    }
    printf("%d", ans);
}