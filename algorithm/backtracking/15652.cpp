#include <cstdio>
#include <vector>

using namespace std;

vector <int> v;
int n, m;

void Solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) 
            printf("%d ",v[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!v.empty() && v.back() > i) continue;
        v.push_back(i);
        Solve(cnt + 1);
        v.pop_back();
    }
}
int main() {
    scanf("%d %d", &n, &m);
    Solve(0);
}