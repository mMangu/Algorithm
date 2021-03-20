#include <cstdio>

bool check[102];

int main() {
    check[1] = true;
    for (int i = 2; i <= 1000; i++) {
        if (check[i] == false) {
            for (int j = i * i; j <= 1000; j += i)
                check[j] = true;
        }
    }
    int N; scanf("%d", &N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp; scanf("%d", &tmp);
        if (!check[tmp]) ans++;
    }
    printf("%d", ans);
}