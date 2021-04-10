#include <cstdio>
#include <cmath>

int pow(int x) { return x * x; }
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int n; scanf("%d", &n);
        int ans = 0;
        while (n--) {
            int cx, cy, r; scanf("%d %d %d", &cx, &cy, &r);
            double s_dist = sqrt(pow(x1 - cx) + pow(y1 - cy));
            double e_dist = sqrt(pow(x2 - cx) + pow(y2 - cy));
            if (s_dist < r && e_dist < r) continue;
            if (s_dist < r) ans++;
            else if (e_dist < r) ans++;
        }
        printf("%d\n", ans);
    }
}