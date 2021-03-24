#include <cstdio>

#define MOD 1000000007
using ll = long long;

ll A[3][3] = {{1, 1}, {1, 0}}, ans[3][3] = {{1, 0}, {0, 1}}, tmp[3][3];

void matrixMul(ll x[3][3], ll y[3][3]) { // x y를 곱해서 x 에 더함
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                tmp[i][j] += x[i][k] * y[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    ll N; scanf("%lld", &N);
    N--;
    while (N > 0) {
        if (N & 1) matrixMul(ans, A);
        matrixMul(A, A);
        N /= 2;
    }
    printf("%lld", ans[0][0]);
}