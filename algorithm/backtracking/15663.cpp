#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10], N, M;
bool check[10];
vector <int> v;

void solve() {
    if (v.size() == M) {
        for (auto iter: v) printf("%d ", iter);
        printf("\n");
        return;
    } else {
        int before = -1;
        for (int i = 0; i < N; i++) {
                if (!check[i] && (i == 0 || before != arr[i])) {
                before = arr[i];
                v.push_back(arr[i]);
                check[i] = true;
                solve();
                v.pop_back();
                check[i] = false;
            }
        }
        return;
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    solve();
}