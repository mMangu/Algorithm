#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100005];
int check[100005];
queue <int> q;

int main() {
    int N, K; scanf("%d %d", &N, &K);
    for (int i = 0; i <= 100000; i++) arr[i] = 1e9;
    arr[N] = 0;
    q.push(N);
    while (true) {
        int x = q.front();
        if (x == K) break;
        q.pop();
        if (x - 1 >= 0 && !check[x - 1]) {
            q.push(x - 1);
            check[x - 1] = true;
            arr[x - 1] = min(arr[x - 1], arr[x] + 1);
        }
        if (2 * x <= 100000 && !check[2 * x]) {
            q.push(2 * x);
            check[2 * x] = true;
            arr[2 * x] = min(arr[2 * x], arr[x] + 1);
        }
        if (x + 1 <= 100000 && !check[x + 1]) {
            q.push(x + 1);
            check[x + 1] = true;
            arr[x + 1] = min(arr[x + 1], arr[x] + 1);
        }
    }
    printf("%d", arr[K]);
}