#include <cstdio>

int arr[100005];
int tree[400005];

int init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    int left = init(node * 2, start, mid);
    int right = init(node * 2 + 1, mid + 1, end);
    return tree[node] = left + right;
}

int sum(int node, int start, int end, int left, int right) {
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    init(1, 0, N - 1);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", sum(1, 0, N - 1, a - 1, b - 1));
    }
}