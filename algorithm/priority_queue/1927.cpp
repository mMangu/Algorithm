#include <cstdio>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int N; scanf("%d", &N);
    while (N--) {
        int ipt; scanf("%d", &ipt);
        if (ipt == 0 && pq.empty()) printf("0\n");
        else {
            if (ipt == 0) {
                printf("%d\n", pq.top());
                pq.pop();
            } else {
                pq.push(ipt);
            }
        }
    }
}