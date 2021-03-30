#include <cstdio>
#include <algorithm>
#define INF 1e9
using namespace std;

int arr[100005], tree_MIN[400005], tree_MAX[400005];

int init_MIN(int node, int start, int end) {
    if (start == end) return tree_MIN[node] = arr[start];
    int mid = (start + end) / 2;
    int left = init_MIN(2 * node, start, mid);
    int right = init_MIN(2 * node + 1, mid + 1, end);
    return tree_MIN[node] = min(left, right);
}

int query_MIN(int node, int start, int end, int left, int right) {
    if (start > right || end < left) return INF;
    if (left <= start && end <= right) return tree_MIN[node];
    int mid = (start + end) / 2;
    return min(query_MIN(2 * node, start, mid, left, right), query_MIN(2 * node + 1, mid + 1, end, left, right));
}

int init_MAX(int node, int start, int end) {
    if (start == end) return tree_MAX[node] = arr[start];
    int mid = (start + end) / 2;
    int left = init_MAX(2 * node, start, mid);
    int right = init_MAX(2 * node + 1, mid + 1, end);
    return tree_MAX[node] = max(left, right);
}

int query_MAX(int node, int start, int end, int left, int right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return tree_MAX[node];
    int mid = (start + end) / 2;
    return max(query_MAX(2 * node, start, mid, left, right), query_MAX(2 * node + 1, mid + 1, end, left, right));
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);
    init_MIN(1, 0, N - 1);
    init_MAX(1, 0, N - 1);
    // for (int i = 1; i <= 40; i++) printf("%d ", tree_MIN[i]);
    // printf("\n");
    // for (int i = 1; i <= 40; i++) printf("%d ", tree_MAX[i]);
    // printf("\n");
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d %d\n", query_MIN(1, 0, N - 1, a - 1, b - 1), query_MAX(1, 0, N - 1, a - 1, b - 1));
    }
}