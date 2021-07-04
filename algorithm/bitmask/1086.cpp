#include <iostream>
#include <string>
#include <cstring>
#include <numeric>

using namespace std;
using ll = long long;

ll arr[16];
string input[16];
ll dp[102][1 << 15], pw[55], len[16];
ll K, N;

ll fac(ll n) {
    ll ans = n;
    while (--n) {
        ans *= n;
    }
    return ans;
}

ll dpf(ll mod, ll state) {
    ll &ret = dp[mod][state];
    if (~ret) return ret;
    if (state + 1 == 1 << N) {
        if (mod) return 0;
        else return 1;
    }
    ret = 0;
    for (int i = 0; i < N; i++) {
        if (!(state & (1 << i))) {
            ll num = mod * pw[len[i]] + arr[i];
            ret += dpf(num % K, state | (1 << i));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    cin >> K;
    for (int i = 0; i < N; i++) {
        len[i] = input[i].size();
        ll t = 0;
        for (auto c : input[i]) {
            t *= 10;
            t %= K;
            t += c - '0';
            t %= K;
        }
        arr[i] = t;
    }

    pw[0] = 1 % K;
    for (int i = 1; i < 55; i++) {
        pw[i] = (pw[i - 1] * 10) % K;
    }
    memset(dp, -1, sizeof(dp));
    ll p = dpf(0, 0);
    if (p == 0) {
        cout << "0/1";
        return 0;
    }
    ll q = fac(N);
    ll divider = gcd(p, q);
    cout << p / divider << "/" << q / divider;
}