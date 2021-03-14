#include <cstdio>
#include <queue>

using namespace std;

typedef struct {
    int y, x;
}Dir;
Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int MAP[1002][1002], check[1002][1002][2], N, M;
queue <pair<pair<int, int>, int>> q;

int solve() {
    q.push(make_pair(make_pair(0, 0), 1));
    check[0][0][1] = 1;
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();
        if (x == M - 1 && y == N - 1) return check[y][x][block];

        for (int i = 0; i < 4; i++) {

            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {

                if (MAP[nextY][nextX] == 1 && block) {
                    check[nextY][nextX][block - 1] = check[y][x][block] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), block - 1));
                }

                else if (MAP[nextY][nextX] == 0 && check[nextY][nextX][block] == 0) {
                    check[nextY][nextX][block] = check[y][x][block] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), block));
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            scanf("%1d", &MAP[i][j]);
    printf("%d", solve());
}
