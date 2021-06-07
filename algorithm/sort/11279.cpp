#include <cstdio>
#include <vector>

using namespace std;

vector<int> maxHeap(2);
int heapSize;

void push(const int e) {
    if (heapSize == maxHeap.size() - 1) maxHeap.resize(maxHeap.size() * 2);
    int curNode = ++heapSize;
    while (curNode != 1 && maxHeap[curNode / 2] < e) {
        maxHeap[curNode] = maxHeap[curNode / 2];
        curNode /= 2;
    }
    maxHeap[curNode] = e;
}

int pop() {
    if (!heapSize) return 0;
    int max = maxHeap[1];
    int lastE =  maxHeap[heapSize--];
    int curNode = 1, child = 2;
    while (child <= heapSize) {
        if (child < heapSize && maxHeap[child] < maxHeap[child + 1]) child++;
        if (lastE >= maxHeap[child]) break;
        maxHeap[curNode] = maxHeap[child];
        curNode = child;
        child *= 2;
    }
    maxHeap[curNode] = lastE;
    return max;
}

int main() {
    int N; scanf("%d", &N);
    while (N--) {
        int ipt; scanf("%d", &ipt);
        if (!ipt) printf("%d\n", pop());
        else push(ipt);
    }
}