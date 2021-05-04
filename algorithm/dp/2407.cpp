#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dp[102][102];

string big_num_add(string a, string b) {
    int sum = 0;
    string result;
    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m) {
    if (n < m || m < 0) return "0";
    if (n == m || m == 0) return "1";
    if (dp[n][m].length()) return dp[n][m];
    return dp[n][m] = big_num_add(combination(n - 1, m - 1), combination(n - 1, m));
}

int main() {
    int n, m; cin >> n >> m;
    cout << combination(n, m);
}