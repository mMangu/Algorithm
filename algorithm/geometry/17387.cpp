#include <cstdio>
#include <utility>
#define x first
#define y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll ccw(pll a, pll b, pll c) {
    ll ans =  (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    if (ans > 0) return 1;
    else if (ans < 0) return -1;
    else return 0; 
}

bool check(pll a, pll b, pll c, pll d) {
    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0; 
}
int main() {
    pll input[4];
    for (int i = 0; i < 4; i++)
        scanf("%lld %lld", &input[i].x, &input[i].y);
    if (check(input[0], input[1], input[2], input[3])) printf("1");
    else printf("0");
}