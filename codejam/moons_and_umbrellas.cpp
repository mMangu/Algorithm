#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string s;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int x, y; scanf("%d %d", &x, &y);
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == 'C' && s[i + 1] == 'J') ans += x;
            else if (s[i] == 'J' && s[i + 1] == 'C') ans += y;
            else if (s[i] == 'C' && s[i + 1] == '?') s[i + 1] = 'C';
            else if (s[i] == 'J' && s[i + 1] == '?') s[i + 1] = 'J';
        }
        printf("Case #%d: %d\n", t, ans);
    }
}