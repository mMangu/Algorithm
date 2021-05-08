#include <cstdio>

using ll = long long;

ll ccw(ll a, ll b, ll c, ll d, ll e, ll f) {
    ll ans =  (a * d + c * f + e * b) - (b * c + d * e + f * a);
    if (ans > 0) return 1;
    else if (ans < 0) return -1;
    else return 0; 
}

int main() {
    ll x1, y1, x2, y2; scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    ll x3, y3, x4, y4; scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
    ll abc = ccw(x1, y1, x2, y2, x3, y3);
    ll abd = ccw(x1, y1, x2, y2, x4, y4);
    ll dca = ccw(x4, y4, x3, y3, x1, y1);
    ll dcb = ccw(x4, y4, x3, y3, x2, y2);
    if (abc * abd <= 0 && dca * dcb <= 0) printf("1");
    else printf("0");
}