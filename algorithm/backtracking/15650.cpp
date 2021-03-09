#include <cstdio>
#include <vector>

using namespace std;

int n, m;
bool check[10];
vector <int> v;

void Solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++)
            printf("%d ",v[i]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == true || (!v.empty() && v.back() >= i)) continue;
        check[i] = true;
        v.push_back(i);
        Solve(cnt + 1);
        check[i] = false;
        v.pop_back();
    }
}

int main() {
    scanf("%d %d", &n, &m);
    Solve(0);
}