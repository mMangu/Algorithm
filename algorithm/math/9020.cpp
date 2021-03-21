#include <cstdio>

bool prime[10004];

int main() {
    int T; scanf("%d", &T);
    for (int i = 2; i <= 10000; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= 10000; j+=i)
                prime[j] = true;
        }
    }
    while (T--) {
        int N; scanf("%d", &N);
        int a = N / 2, b = N / 2;
        while (a > 1) {
            if (!prime[a] && !prime[b]) {
                printf("%d %d\n", a, b);
                break;
            } else {
                a--; b++;
            }
        }
    }
}