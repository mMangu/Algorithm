#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10], N, M;
vector <int> v;

void solve(int start) {
    if (v.size() == M) {
        for(auto iter : v) printf("%d ", iter);
        printf("\n");
        return;
    } else {
        for (int i = start; i < N; i++) {
            v.push_back(arr[i]);
            solve(i);
            v.pop_back();
        }
        return;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    sort(arr, arr + N);
    solve(0);
}
