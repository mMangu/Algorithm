#include <cstdio>

using ll = long long;

bool prime[300000];

int main() {
    prime[1] = true;
    for (ll i = 2; i <= 2 * 123456; i++) {
        if (!prime[i]) {
            for (ll j = i * i; j <= 2 * 123456; j += i)
                prime[j] = true;
        }
    }
    while (1) {
        int n; scanf("%d", &n);
        if (n == 0) return 0;
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (!prime[i]) cnt++;
        }
        printf("%d\n", cnt);
    }
}