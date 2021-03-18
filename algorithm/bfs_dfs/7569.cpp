#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int arr[102][102][102], N, M, H, check, ans;
queue <pair<pair<int, int>, int>> q;

void Solve() {
    while (!q.empty()) {
        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second;
        q.pop();
        check--;
        ans = max(ans, arr[z][y][x] - 1);
        if (z + 1 < H && !arr[z + 1][y][x] && arr[z + 1][y][x] != -1) {
            q.push(make_pair(make_pair(z + 1, y) , x));
            arr[z + 1][y][x] = arr[z][y][x] + 1;
        }
        if (y + 1 < N && !arr[z][y + 1][x] && arr[z][y + 1][x] != -1) {
            q.push(make_pair(make_pair(z, y + 1) , x));
            arr[z][y + 1][x] = arr[z][y][x] + 1;
        }
        if (x + 1 < M && !arr[z][y][x + 1] && arr[z][y][x + 1] != -1) {
            q.push(make_pair(make_pair(z, y) , x + 1));
            arr[z][y][x + 1] = arr[z][y][x] + 1;
        }
        if (z - 1 >= 0 && !arr[z - 1][y][x] && arr[z - 1][y][x] != -1) {
            q.push(make_pair(make_pair(z - 1, y) , x));
            arr[z - 1][y][x] = arr[z][y][x] + 1;
        }
        if (y - 1 >= 0 && !arr[z][y - 1][x] && arr[z][y - 1][x] != -1) {
            q.push(make_pair(make_pair(z, y - 1) , x));
            arr[z][y - 1][x] = arr[z][y][x] + 1;
        }
        if (x - 1 >= 0 && !arr[z][y][x - 1] && arr[z][y][x - 1] != -1) {
            q.push(make_pair(make_pair(z, y) , x - 1));
            arr[z][y][x - 1] = arr[z][y][x] + 1;
        }
    }
}

void input() {
    scanf("%d %d %d", &M, &N, &H);
    check = M * N * H;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &arr[k][i][j]);
                if(arr[k][i][j] == 1) q.push(make_pair(make_pair(k, i), j));
                else if (arr[k][i][j] == -1) check--;
            }
        }
    }
}

int main() {
   input();
   Solve();
   if (!check) printf("%d", ans);
   else printf("-1");
}