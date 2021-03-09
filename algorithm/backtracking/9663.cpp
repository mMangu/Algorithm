#include <cstdio>
#include <algorithm> 

using namespace std;

int n, ans, check[16];

bool Possible(int x) {
    for (int i = 0; i < x; i++)
        if (check[i] == check[x] || abs(check[i] - check[x]) == x - i) return false;
    return true;
}

void Solve(int x) {
    if (x == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        check[x] = i;
        if (Possible(x)) Solve(x + 1);
    }
}

int main() {
    scanf("%d", &n);
    Solve(0);
    printf("%d", ans);
}
