#include <cstdio>

using ll = long long;

ll cal(ll i) {
    return i * i * i;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        ll N; scanf("%lld", &N);
        bool flag = false;
        for (ll i = 1; i <= 10000; i++) {
            if (flag) break;
            ll l = i, r = 10000;        
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (cal(i) + cal(mid) > N) r = mid - 1;
                else if(cal(i) + cal(mid) < N) l = mid + 1;
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
}
