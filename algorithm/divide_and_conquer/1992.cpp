#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int map[65][65];
string s;

void solve(int y, int x, int N) {
    int cnt = 0;
    for (int i = y; i < N + y; i++)
        for (int j = x; j < N + x; j++)
            if(map[i][j]) cnt++;
    if (cnt == N * N) {
        s += '1';
        return;
    } else if (!cnt) {
        s += '0';
        return;
    }
    s += "(";
    solve(y, x, N / 2);
    solve(y, x + N / 2, N / 2);
    solve(y + N / 2, x, N / 2);
    solve(y + N / 2, x + N / 2, N / 2);
    s += ")";
    return;
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d" ,&map[i][j]);
    solve(0, 0, N);
    cout << s;
}