#include <cstdio>
#define MOD 1000000007

using ll = long long;

ll fac[4000006];

ll pow(ll a, ll b) {
    if (b == 1) return a;
    ll half = pow(a, b / 2) % MOD;
    if (b % 2) return ((half * half) % MOD * a) % MOD;
    else return half * half % MOD;
}

void facCal(ll N) {
    fac[0] = 1; fac[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
}

int main() {
    int N, K; scanf("%d %d", &N, &K);
    facCal(N);
    ll ans = (fac[N] % MOD) * (pow((fac[N - K] * fac[K]) % MOD, MOD - 2) % MOD) % MOD;
    printf("%lld", ans);
}

//페르마의 소정리 B^(P-1) = 1 (mod P)
//B * B^(P-2) = 1 (mod P)
//B^(P-2) = B^-1 (mod P)

//(N! / (N-k)!K!) % P = N! * ({(N-K)!K!}^(P-2) % P) % P

