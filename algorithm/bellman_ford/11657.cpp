//벨멘포드 알고리즘은 다익스트라와 다르게 음의 가중치 문제도 해결 가능함

#define INF 1e18
#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

ll d[502];
vector <pair<int, int>> v[502];
bool cycle;

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int A, B, C; scanf("%d %d %d", &A, &B, &C);
        v[A - 1].push_back(make_pair(B - 1, C));
    }
    for (int i = 1; i <= N; i++) d[i] = INF;
    for (int i = 0; i < N; i++) {
        // N-1 번의 음의 사이클 + N 번쨰는 싸이클 존재 여부 확인
        for (int j = 0; j < N; j++) {
            for (auto &p: v[j]) {
                int next = p.first;
                int distance = p.second;
                if (d[j] != INF && d[next] > d[j] + distance) {
                    d[next] = d[j] + distance;
                    if (i == N - 1) cycle = true;
                    //N 번째 루프에 값이 갱신되면 음의 싸이클 존재
                }
            }
        }
    }
    if (cycle) printf("-1");
    else {
        for (int i = 1; i < N; i++) printf("%lld\n", d[i] != INF ? d[i] : -1);
    }
}
