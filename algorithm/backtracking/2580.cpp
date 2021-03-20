#include <cstdio>
#include <cstdlib>

int arr[10][10];
bool row[10][10];
bool col[10][10];
bool box[10][10];

void dfs(int cnt) {
    int x = cnt / 9;
    int y = cnt % 9;
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    if (!arr[x][y]) {
        for (int i = 1; i <= 9; i++) {
            if (!row[x][i] && !col[y][i] && !box[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                col[y][i] = true;
                box[(x / 3) * 3 + (y / 3)][i] = true;
                arr[x][y] = i;
                dfs(cnt + 1);
                arr[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                box[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else dfs(cnt + 1);
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j]) {
                row[i][arr[i][j]] = true;
                col[j][arr[i][j]] = true;
                box[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
            }
        }
    }
    dfs(0);
}