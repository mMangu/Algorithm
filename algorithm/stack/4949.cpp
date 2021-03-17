#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    while (true){
        string str;
        stack <char> s;
        bool flag = false;
        getline(cin, str);
        if (str.length() == 1) break;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') s.push(str[i]);
            if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else flag = true;
            }
            if (str[i] == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else flag = true;
            }
        }
        if (s.empty() && !flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}