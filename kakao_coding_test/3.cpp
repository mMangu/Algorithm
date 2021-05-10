#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check[1000006];

string solution(int n, int k, vector<string> cmd) {
    for (int i = 0; i < n; i++) check[i] = true;
    bool flag = false;
    stack<int> s;
    string answer = "";
    for (int i = 0; i < cmd.size(); i++) {
        switch (cmd[i][0]) {
        case 'U':
            for (int j = 0; j < cmd[i][2] - '0'; j++) {
                k--;
                if (!check[k]) j--;
            }
            break;
        case 'D':
            for (int j = 0; j < cmd[i][2] - '0'; j++) {
                k++;
                if (!check[k]) j--;
            }
            break;
        case 'C':
            flag = false;
            s.push(k);
            check[k] = false;
            while (!check[k]) {
                k++;
                if (k >= n) {
                    flag = true;
                    break;
                }
            }
            if (flag) { 
                while (!check[k]) {
                    k--;
                }
            }            
            break;
        case 'Z':
            if (!s.empty()) {
                check[s.top()] = true;
                s.pop();
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) answer += 'O';
        else answer += 'X';
    }
    return answer;
}