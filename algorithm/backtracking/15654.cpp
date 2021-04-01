#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10], N, M;
bool check[10];
vector <int> v;

void solve(int idx) {
    if (v.size() == M) {
        for (auto iter : v) printf("%d ", iter);
        printf("\n");
        return;
    } else {
        for (int i = 0; i < N; i++) {
            if (check[i]) continue;
            v.push_back(arr[i]);
            check[i] = true;
            //printf("%d ", arr[idx]);
            solve(idx + 1);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    solve(0);
}