#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[26][26], cnt , N;
vector <int> v;
priority_queue <int> q;

void dfs(int x, int y) {
    if (!arr[x][y]) return;
    else arr[x][y] = 0;
    cnt++;
    if (x + 1 < N)
        dfs(x + 1, y);
    if (x - 1 >= 0)
        dfs(x - 1, y);
    if (y + 1 < N)
        dfs(x, y + 1);
    if (y - 1 >= 0)
        dfs(x, y - 1);
    return;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) {
                cnt = 0;
                dfs(i , j);
                q.push(-cnt);
            }
        }
    }
    printf("%lu\n", q.size());
    while (!q.empty()) {
        printf("%d\n", -q.top());
        q.pop();
    }
}