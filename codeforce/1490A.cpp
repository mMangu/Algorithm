#include <cstdio>
#include <algorithm>

using namespace std;

int a[52];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", a + i);
        int ans = 0;
        for (int i = 0; i < N - 1; i++) {
            int L = max(a[i], a[i + 1]), S = min(a[i], a[i + 1]);
            if (L > S * 2) {
                int divide = (L % S) ? L / S + 1: L / S;
                while (divide > 2) {
                    divide = divide % 2 ? divide / 2 + 1 : divide / 2;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}