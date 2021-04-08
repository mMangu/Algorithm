#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
int map[21][21], dist[21][21], sharkSize = 2, N, ans, eat, min_dist, min_x, min_y;
int Dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
bool canEat = true;
pair<int, int> shark;
queue<pair<int, int>> q;

void bfs() {
    q = queue<pair<int, int>> ();
    q.push(make_pair(shark.first, shark.second));
    dist[shark.first][shark.second] = 0;
    while (!q.empty()) {
        auto [y, x] = q.front();
        //int y = q.front().first, x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = y + Dir[i][0], nextX = x + Dir[i][1];
            if (nextY < 0 || nextY > N || nextX < 0 || nextX > N) continue;
            if (dist[nextY][nextX] != -1 || map[nextY][nextX] > sharkSize) continue;
            dist[nextY][nextX] = dist[y][x] + 1;
            if (map[nextY][nextX] != 0 && map[nextY][nextX] < sharkSize) {
                if(min_dist > dist[nextY][nextX]) {
                    min_x = nextX;
                    min_y = nextY;
                    min_dist = dist[nextY][nextX];
                } else if (min_dist == dist[nextY][nextX]) {
                    if (min_y == nextY) {
                        if (min_x > nextX) {
                            min_x = nextX;
                            min_y = nextY;
                        }
                    } else if (min_y > nextY) {
                        min_x = nextX;
                        min_y = nextY;
                    }
                }
            }
            q.push(make_pair(nextY, nextX));
        } 
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                shark.first = i;
                shark.second = j;
                map[i][j] = 0;
            }
        }
    }
    while (true) {
        min_dist = INF;
        min_x = INF;
        min_y = INF;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = -1;
        bfs();
        if (min_x != INF && min_y != INF) {
            ans += dist[min_y][min_x];
            eat++;
            if (eat == sharkSize) {
                sharkSize++;
                eat = 0;
            }
            map[min_y][min_x] = 0;
            shark.first = min_y;
            shark.second = min_x;
        } else break;
    }
    printf("%d", ans);
}
