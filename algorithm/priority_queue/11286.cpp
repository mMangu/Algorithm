#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

struct T {
    int x, y;
    bool operator()(const T &a, const T &b) {
        if (a.x == b.x) return a.y > b.y;
        else return a.x > b.x;
    }
};

int main() {
    int N; scanf("%d", &N);
    priority_queue<T, vector<T>, T> pq;
    while (N--) {
        int input; scanf("%d", &input);
        if (!input) {
            if (pq.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", pq.top().y);
                pq.pop();
            }
        } else {
            pq.push({abs(input), input});
        }
    }
}
