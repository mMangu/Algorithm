#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
string tmp = "";
bool checkMinus;

int main() {
    cin >> s;
    int ans = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (checkMinus) ans -= stoi(tmp);
            else ans += stoi(tmp);
            tmp = "";
            if (s[i] == '-') checkMinus = true;
        } else {
            tmp += s[i];
        }
    }
    printf("%d", ans);
}