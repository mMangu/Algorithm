#include <cstdio>
#include <algorithm>

using namespace std;

bool check[10004];

int main() {
    check[1] = true;
    for (int i = 2; i <= 10000; i++) {
        if (!check[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                check[j] = true;
            }
        }
    }
    int M, N; scanf("%d %d", &M, &N);
    int ans = 0, MIN = 1e9;
    for (int i = M; i <= N; i++) {
        if (!check[i]) {
            ans += i;
            MIN = min(MIN, i);
        }
    }
    if (ans) printf("%d\n%d", ans, MIN);
    else printf("-1");
}