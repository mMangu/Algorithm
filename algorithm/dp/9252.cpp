#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1003][1003];

int max(int a, int b) { return a > b ? a : b; }
int main() {
    string a, b; cin >> a >> b;
    a = '0' + a, b = '0' + b;
    for (int i = 1; i < a.length(); i++) {
        for (int j = 1; j < b.length(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[a.length() - 1][b.length() - 1] << endl;
    // for (int i = 0; i < a.length(); i++) {
    //     for (int j = 0; j < b.length(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<char> ans;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 1 && j >= 1) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans.push_back(a[i]);
            i--, j--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}