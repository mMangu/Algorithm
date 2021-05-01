#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

double num[30];

double cal(double a, double b, char oper) {
	double res = 0.;
	switch (oper) {
	case '+':
		res = b + a;
		break;
	case '-':
		res = b - a;
		break;
	case '*':
		res = b * a;
		break;
	case '/':
		res = b / a;
		break;
	}
	return res;
}

int main() {
    int N; cin >> N;
    string str; cin >> str;
    stack<double> s;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') s.push(num[str[i] - 'A']);
        else {
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(cal(x, y, str[i]));
        }
    }
	printf("%.2lf", s.top());
}