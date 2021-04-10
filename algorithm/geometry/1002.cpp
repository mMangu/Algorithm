#include <cstdio>
#include <cmath>
int max(int a, int b) { return a > b ? a: b; }
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x1, y1, r1, x2, y2, r2; scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            printf("-1\n");
            continue;        
        } else if (x1 == x2 && y1 == y2 && r1 != r2) {
            printf("0\n");
            continue;
        }
        double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (dist > max(r1, r2)) {
            if (r1 + r2 < dist) printf("0\n");
            else if (r1 + r2 == dist) printf("1\n");
            else printf("2\n");
        } else {
            if (abs(r1 - r2) == dist) printf("1\n");
            else if (abs(r1 - r2) > dist) printf("0\n");
            else printf("2\n");
        }
    }
}