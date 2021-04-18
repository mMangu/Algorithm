#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> d;
    for (int i = 0; i < s.length(); i++) d.push_back(s[i]);    
    for (int i = 0; i < s.length(); i++) {
        stack<char> arr;
        if (i != 0) {
            int tmp = d.front();
            d.pop_front();
            d.push_back(tmp);
        }
        for (int j = 0; j < s.length(); j++) {
            
            if (d[j] == '}' && !arr.empty() && arr.top() == '{') {
                arr.pop();
                continue;
            }
            else if (d[j] == ']' && !arr.empty() && arr.top() == '[') {
                arr.pop();
                continue;
            }
            else if (d[j] == ')' && !arr.empty() && arr.top() == '(') {
                arr.pop();                
                continue;
            }
            else arr.push(d[j]);
        }
        if (arr.empty()) answer++;
    }
    return answer;
}

int main() {
    string s = "[](){}";
    printf("%d", solution(s));
}