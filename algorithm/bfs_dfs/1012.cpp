#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool arr[52][52];
int M, N, K, cnt; 

void dfs(int x, int y) {
    if (!arr[x][y]) return;
    else arr[x][y] = false;
    if (x + 1 < M)
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
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &M, &N, &K);
        for (int i = 0; i < K; i++) {
            int x, y; scanf("%d %d", &x, &y);
            arr[x][y] = true;
        }
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[j][i]) {
                    dfs(j, i);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}