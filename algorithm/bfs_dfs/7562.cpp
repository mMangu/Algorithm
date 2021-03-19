#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair <int, int> P;
int arr[302][302];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int ans = 0;
        queue <pair<int, int>> q;
        int I; scanf("%d", &I);
        int curX, curY; scanf("%d %d", &curX, &curY);
        int destX, destY; scanf("%d %d", &destX, &destY);
        for (int i = 0; i < I; i++) 
            for (int j = 0; j < I; j++)
                arr[i][j] = 0;
        q.push(P(curX, curY));
        while (1) {
            int nextX = q.front().first;
            int nextY = q.front().second;
            q.pop();
            ans = max(ans, arr[nextX][nextY]);
            if (nextX == destX && nextY == destY) {
                printf("%d\n", ans);
                break;
            }
            if (nextX + 1 < I && nextY + 2 < I && !arr[nextX + 1][nextY + 2]) {
                q.push(P(nextX + 1, nextY + 2));
                arr[nextX + 1][nextY + 2] = arr[nextX][nextY] + 1;
            }
            if (nextX + 2 < I && nextY + 1 < I && !arr[nextX + 2][nextY + 1]) {
                q.push(P(nextX + 2, nextY + 1));
                arr[nextX + 2][nextY + 1] = arr[nextX][nextY] + 1;
            } 

            if (nextX + 2 < I && nextY - 1 >= 0 && !arr[nextX + 2][nextY - 1]) {
                q.push(P(nextX + 2, nextY - 1));
                arr[nextX + 2][nextY - 1] = arr[nextX][nextY] + 1;
            } 
            if (nextX + 1 < I && nextY - 2 >= 0 && !arr[nextX + 1][nextY - 2]) {
                q.push(P(nextX + 1, nextY - 2));
                arr[nextX + 1][nextY - 2] = arr[nextX][nextY] + 1;
            }

            if (nextX - 1 >= 0 && nextY - 2 >= 0 && !arr[nextX - 1][nextY - 2]) {
                q.push(P(nextX - 1, nextY - 2));
                arr[nextX - 1][nextY - 2] = arr[nextX][nextY] + 1;
            } 

            if (nextX - 2 >= 0 && nextY - 1 >= 0 && !arr[nextX - 2][nextY - 1]) {
                q.push(P(nextX - 2, nextY - 1));
                arr[nextX - 2][nextY - 1] = arr[nextX][nextY] + 1;
            } 

            if (nextX - 2 >= 0 && nextY + 1 < I && !arr[nextX - 2][nextY + 1]) {
                q.push(P(nextX - 2, nextY + 1));
                arr[nextX - 2][nextY + 1] = arr[nextX][nextY] + 1;
            } 

            if (nextX - 1 >= 0 && nextY + 2 < I && !arr[nextX - 1][nextY + 2]) {
                q.push(P(nextX - 1, nextY + 2));
                arr[nextX - 1][nextY + 2] = arr[nextX][nextY] + 1;
            } 
        }
    }
}