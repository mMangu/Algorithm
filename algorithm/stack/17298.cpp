#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

stack <int> s;
vector <int> v;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    vector <int> ans(v.size(), -1);
    for (int i = 0; i < v.size(); i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    for (const auto &iter : ans) printf("%d ", iter);
}