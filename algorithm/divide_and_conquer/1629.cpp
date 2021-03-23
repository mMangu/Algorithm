#include <cstdio>

using ll = long long;

ll A, B, C;
ll solve(ll A, ll B) {
    if (B == 1) return A;
    ll tmp = solve(A, B / 2);
    if (B % 2) return ((tmp * tmp) % C * A) % C;
    else return (tmp * tmp % C);
}

int main() {
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", solve(A % C, B) % C);
}