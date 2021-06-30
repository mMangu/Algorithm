#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll ccw(pll a, pll b, pll c) {
    ll ret = a.x * b.y + b.x * c.y + c.x * a.y;
    ret = ret - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}

bool check(pll a, pll b, pll c, pll d) {
    ll abc = ccw(a, b, c), abd = ccw(a, b, d);
    ll cda = ccw(c, d, a), cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    } else {
        return abc * abd <= 0 && cda * cdb <= 0;
    }
}

int main() {
    pll a, b; scanf("%lld %lld %lld %lld", &a.x, &a.y, &b.x, &b.y);
    pll c, d; scanf("%lld %lld %lld %lld", &c.x, &c.y, &d.x, &d.y);
    if (check(a, b, c, d)) {
        printf("1\n");
        if (a >= b) swap(a, b);
        if (c >= d) swap(c, d);
        if (b == c) {
            printf("%lld %lld", b.x, b.y);
            return 0;
        } else if (a == d) {
            printf("%lld %lld", a.x, a.y);               
            return 0;
        }
        if (a.x != b.x && c.x != d.x) {
            double f1[3], f2[3];
            f1[0] = double(a.y - b.y) / double(a.x - b.x);
            f1[1] = -1;
            f1[2] = double(a.y - b.y) / double(a.x - b.x) * a.x * -1 + a.y;
            f2[0] = double(c.y - d.y) / double(c.x - d.x);
            f2[1] = -1;
            f2[2] = double(c.y - d.y) / double(c.x - d.x) * c.x * -1 + c.y;        
            if (f1[0] == f2[0]) {
                return 0;
            }
            double x1 = (f1[2] - f2[2]) / (f1[0] - f2[0]) * -1;
            double y1 = f1[0] * x1 + f1[2];
            printf("%.9lf %.9lf", x1, y1);
        } else { // x = c 와 같은 상황
            if (a.x == b.x) {
                double f2[3];
                f2[0] = double(c.y - d.y) / double(c.x - d.x);
                f2[1] = -1;
                f2[2] = double(c.y - d.y) / double(c.x - d.x) * c.x * -1 + c.y;
                printf("%lld %.9lf", a.x, f2[0] * double(a.x) + f2[2]);
            }
            else {
                double f1[3];
                f1[0] = double(a.y - b.y) / double(a.x - b.x);
                f1[1] = -1;
                f1[2] = double(a.y - b.y) / double(a.x - b.x) * a.x * -1 + a.y;
                printf("%lld %.9lf", c.x, f1[0] * double(c.x) + f1[2]);
            }

        }
    } else {
        printf("0");
    }
}