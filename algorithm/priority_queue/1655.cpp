#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int>> mq;
    priority_queue<int> Mq;
    while (N--) {
        int ipt; scanf("%d", &ipt);
        mq.size() >= Mq.size() ? Mq.push(ipt) : mq.push(ipt);
        if (!mq.empty() && !Mq.empty()) {
            if (Mq.top() > mq.top()) {
                int mtmp = mq.top(), Mtmp = Mq.top();
                mq.pop(); Mq.pop();
                mq.push(Mtmp); Mq.push(mtmp);
            }
        }
        printf("%d\n", Mq.top());
    }
}