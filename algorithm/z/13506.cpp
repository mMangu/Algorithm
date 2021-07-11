#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Z[1000006], pmax[1000006];

int main() {
    string s; cin >> s;
    int N = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < N; i++) {
        if (i > R) {
            L = R = i;
            while (R < N && s[R - L] == s[R]) R++;
            Z[i] = R - L; R--;            
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else {
                L = i;
                while (R < N && s[R - L] == s[R]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
    int M = 0;
    for (int i = 1; i < N; i++) {
        M = max(Z[i], M);
        pmax[i] = M;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (Z[N - i] == i) {
            if (pmax[N - i - 1] >= i) ans = max(ans, i);
        }
    }
    if (ans) cout << s.substr(0, Z[N - ans]);
    else printf("-1");
}