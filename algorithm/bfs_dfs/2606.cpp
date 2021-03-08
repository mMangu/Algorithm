#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector <int> v[101];
queue <int> q;
bool check[101];
int ans;

int main() {
    int N; scanf("%d", &N);
    int k; scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int y = v[x][i];
            if (!check[y]) {
                q.push(y);
                check[y] = true;
                ans++;
            }
        }
    }
    printf("%d",ans);
}