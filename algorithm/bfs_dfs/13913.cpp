#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int location[100005], parent[100005];
queue<int> q;

int main() {
    int N, K; scanf("%d %d", &N, &K);
    q.push(N);
    location[N] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == K) break;
        if (2 * cur <= 100000 && !location[2 * cur]) {
            q.push(2 * cur);
            location[2 * cur] = location[cur] + 1;
            parent[2 * cur] = cur;
        }
        if (cur + 1 <= 100000 && !location[cur + 1]) {
            q.push(cur + 1);
            location[cur + 1] = location[cur] + 1;
            parent[cur + 1] = cur;
        }
        if (cur - 1 >= 0 && !location[cur - 1]) {
            q.push(cur - 1);
            location[cur - 1] = location[cur] + 1;
            parent[cur - 1] = cur;
        }
    }
    
    int cnt = location[K];
    stack<int> s;
    printf("%d\n", cnt - 1);
    while (cnt--) {
        s.push(K);
        K = parent[K];
    }
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
}