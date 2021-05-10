#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string input) {
    string tmp;
    string ans;
    for (int i = 0; i < input.length(); i++) {
        if ('0' <= input[i] && input[i] <= '9') ans += input[i];
        else tmp += input[i];
        if (!tmp.empty()) {
            if (tmp == "zero") {
                ans += '0';
                tmp.clear();
            } else if (tmp == "one") {
                ans += '1';
                tmp.clear();
            } else if (tmp == "two") {
                ans += '2';
                tmp.clear();
            } else if (tmp == "three") {
                ans += '3';
                tmp.clear();
            } else if (tmp == "four") {
                ans += '4';
                tmp.clear();
            } else if (tmp == "five") {
                ans += '5';
                tmp.clear();
            } else if (tmp == "six") {
                ans += '6';
                tmp.clear();
            } else if (tmp == "seven") {
                ans += '7';
                tmp.clear();
            } else if (tmp == "eight") {
                ans += '8';
                tmp.clear();
            } else if (tmp == "nine") {
                ans += '9';
                tmp.clear();
            }
        }
    }
    return stoi(ans);
}

int main() {
    cout << solution("one4seveneight") << endl;
    cout << solution("23four5six7") << endl;
    cout << solution("2three45sixseven") << endl;
}