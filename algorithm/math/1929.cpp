#include <cstdio>

using ll = long long;

bool prime[1000006];

int main() {
    int M, N; scanf("%d %d", &M, &N);
    prime[1] = true;
    for (ll i = 2; i <= N; i++) {
        if (!prime[i]) {
            for (ll j = i * i; j <= N; j += i) {
                prime[j] = true;
            }
        }
    }
    for (int i = M; i <= N; i++) {
        if (!prime[i]) printf("%d\n", i);
    }
}