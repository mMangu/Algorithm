#include <cstdio>
#include <vector>

using namespace std;

int n, m; 
vector <int> v;
bool check[10][10];

void Solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (check[cnt + 1][i]) continue;
        check[cnt + 1][i] = true;
        v.push_back(i);
        Solve(cnt + 1);
        check[cnt + 1][i] = false;
        v.pop_back();
    }
}
int main() {
    scanf("%d %d", &n, &m);
    Solve(0);
}