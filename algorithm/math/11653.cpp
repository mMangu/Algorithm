#include <cstdio>

bool prime[10000007];

using ll = long long;

int main() {
    prime[1] = true;
    for (ll i = 2; i <= 10000000; i++) {
        if (!prime[i]) {
            for (ll j = i * i; j <= 10000000; j += i)
                prime[j] = true;
        }
    }
    int N; scanf("%d", &N);
    int i = 2;
    while (N != 1) {
        if (prime[i]) {
            i++;
            continue;
        }
        if (N % i == 0) {
            N = N / i;
            printf("%d\n", i);
        } else{
            i++;
        }
    }  
}