#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool bfs(vector<vector<string>> places, int first_i, int first_y, int first_x) {
    bool flag = true;
    int check[6][6];
    memset(check, 0, sizeof(check));

    queue<pair<int, int>> q;
    q.push( {first_y, first_x} );
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dir[i][0], nextY = y + dir[i][1];

            if (nextX >= 5 || nextX < 0 || nextY >= 5 || nextY < 0) continue;
            if (check[nextY][nextX]) continue;

            if (places[first_i][nextY][nextX] == 'O') {
                q.push( {nextY, nextX} );
                check[nextY][nextX] = check[y][x] + 1;
            } else if ((nextY != first_y && nextX != first_x) && places[first_i][nextY][nextX] == 'P') {
                check[nextY][nextX] = check[y][x] + 1;
                if (check[nextY][nextX] <= 2) flag = false;
            }
        }
    }
    return flag;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer.resize(5, 1);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    if (!bfs(places, i, j, k)) answer[i] = 0;
                }
            } 
        }
    }
    return answer;
}