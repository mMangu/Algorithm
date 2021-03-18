#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair <int, int> P;

int N, M;
int arr[1003][1003], ans, check;
queue <pair<int, int>> q;

void Solve() {
    while (!q.empty()) {
        int Y = q.front().first;
        int X = q.front().second;
        ans = max(ans, arr[Y][X] - 1);
        q.pop();
        check--;
        if (X + 1 < M && !arr[Y][X + 1] && arr[Y][X + 1] != -1) {
            q.push(P(Y, X + 1));
            arr[Y][X + 1] = arr[Y][X] + 1;
        }
        if (X - 1 >= 0 && !arr[Y][X - 1] && arr[Y][X - 1] != -1) {
            q.push(P(Y, X - 1));
            arr[Y][X - 1] = arr[Y][X] + 1;
        }
        if (Y + 1 < N && !arr[Y + 1][X] && arr[Y + 1][X] != -1) {
            q.push(P(Y + 1, X));
            arr[Y + 1][X] = arr[Y][X] + 1;
        }
        if (Y - 1 >= 0 && !arr[Y - 1][X] && arr[Y - 1][X] != -1) {
            q.push(P(Y - 1, X));
            arr[Y - 1][X] = arr[Y][X] + 1;
        }

    }
}
int main() {
    scanf("%d %d", &M, &N);
    check = N * M;
    for (int  i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) q.push(P(i, j));
            else if (arr[i][j] == -1) check--;
        }
    }
    Solve();
    if(!check) printf("%d", ans);
    else printf("-1");
}