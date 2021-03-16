#include <iostream>
#include <string>

using namespace std;

int dp[1002][1002], ans;

int main() {
    string s1; cin >> s1;
    string s2; cin >> s2;

    s1 = '0' + s1;
    s2 = '0' + s2;
    for (int i = 1; i < s2.length(); i++) {
        for (int j = 1; j < s1.length(); j++) {
            if (s1[j] == s2[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i][j - 1] > dp[i - 1][j]) dp[i][j] = dp[i][j - 1];
                else dp[i][j] = dp[i - 1][j];
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
}