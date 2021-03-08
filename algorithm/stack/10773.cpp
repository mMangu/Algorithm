#include <cstdio>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int k; scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int tmp; scanf("%d", &tmp);
        if (tmp) s.push(tmp);
        else s.pop();
    }
    int ans = 0;
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    printf("%d", ans);
}