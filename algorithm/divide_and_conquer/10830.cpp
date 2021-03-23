#include <cstdio>
#define MOD 1000
using ll = long long;

ll A[6][6], tmp[6][6], ans[6][6], N, B;

void matrixCal(ll x[6][6], ll y[6][6]) {   
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++)
                tmp[i][j] += x[i][k] * y[k][j];
            tmp[i][j] %= MOD; 
        }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    scanf("%lld %lld", &N, &B);
    for (int i = 0; i < N; i++) {
        ans[i][i] = 1;
        for (int j = 0; j < N; j++) {
            scanf("%lld", &A[i][j]);
        }
    }

    while (B > 0) {
        if (B & 1) matrixCal(ans, A);
        matrixCal(A, A);
        B /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {    
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
}