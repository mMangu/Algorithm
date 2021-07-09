#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 33;
ll phash[1000006], pow[1000006];
string s;

inline ll mod(ll n) {
    if (n >= 0) return n % MOD;
    return n % MOD + MOD;
}

ll calHash(int l, int r) {
    if (l == 0) return phash[r];
    if (l == r) return s[l];
    return mod(phash[r] - ((phash[l - 1] * pow[r - l + 1]) % MOD + MOD) % MOD);
}

int main() {
    pow[0] = 1;
    for (int i = 1; i < 1000006; i++) pow[i] = mod(pow[i - 1] * 31);
    while (1) {
        char tmp[1000006]; scanf("%s", tmp);
        s = tmp;
        if (s == ".") return 0;

        phash[0] = s[0];
        for (int i = 1; i < s.length(); i++)
            phash[i] = mod(phash[i - 1] * 31 % MOD + s[i]);

        for (int i = 1; i <= s.length(); i++) {
            bool flag = false;
            if (s.length() % i == 0) {
                if (calHash(0, s.length() - i - 1) == calHash(i, s.length() - 1)) flag = true;
                if (i == s.length()) flag = true;
            }
            if (flag) {
                printf("%lu\n", s.length() / i);
                break;
            }
        }
    }    
}