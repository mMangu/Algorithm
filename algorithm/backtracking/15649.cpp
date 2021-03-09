#include <cstdio>
#include <vector>

using namespace std;

int check[10], n, m;
vector <int> v;

void Solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++)
            printf("%d ",v[i]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(i);
        Solve(cnt + 1);
        v.pop_back();
        check[i] = false;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    Solve(0);
}