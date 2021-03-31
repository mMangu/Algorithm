#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[22][22], ans = 2e9, N;
bool check[22];

vector <int> teamA, teamB;

void solve(int idx) {
    if (idx == N + 1) {
        if (teamA.size() == N / 2 && teamB.size() == N / 2) {
            int teamA_result = 0, teamB_result = 0;
            for (int i = 0; i < N / 2; i++) {
                int A_first = teamA[i], B_first = teamB[i];
                for (int j = i + 1; j < N / 2; j++) {
                    if (i == j) continue;
                    int A_second = teamA[j], B_second = teamB[j];
                    teamA_result += (arr[A_first][A_second] + arr[A_second][A_first]);
                    teamB_result += (arr[B_first][B_second] + arr[B_second][B_first]);
                }
            }
            ans = min(abs(teamA_result - teamB_result), ans);
        }
        return;
    }
    teamA.push_back(idx);
    solve(idx + 1);
    teamA.pop_back();

    teamB.push_back(idx);
    solve(idx + 1);
    teamB.pop_back();
    return;
}


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++)
            scanf("%d", &arr[i][j]);
    solve(1);
    printf("%d", ans);
}
