#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input; cin >> input;
    stack<char> s;
    for (int i = 0; i < input.length(); i++) {
        if ('A' <= input[i] && input[i] <= 'Z') cout << input[i];
        else {
            switch (input[i]) {
            case '(':
                    s.push(input[i]);
                    break;
            case '*':
            case '/':
                    while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                    {
                        cout << s.top();
                        s.pop();
                    }
                    s.push(input[i]);
                    break;
            case '+':
            case '-':
                    while (!s.empty() && s.top() != '(') {
                        cout << s.top();
                        s.pop();
                    }
                    s.push(input[i]);
                    break;
            case ')':
                while (!s.empty() && s.top() != '(') {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
                break;
            }
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}