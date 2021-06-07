#include <cstdio>
#include <algorithm>

int arr[10000007], N;

void adjust(int root, int n) {
    int e = arr[root], i;
    for (i = root << 1; i <= n; i <<= 1) {
        if (i < n && arr[i] < arr[i + 1]) i++;
        if (e >= arr[i]) break;
        arr[i >> 1] = arr[i];
    }
    arr[i / 2] = e;
}

void heapSort() {
    for (int i = N >> 1; i >= 1; i--) adjust(i, N);
    for (int i = N - 1; i >= 1; i--) {
        std::swap(arr[1], arr[i + 1]);
        adjust(1, i);
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", arr + i);
    heapSort();
    for (int i = 1; i <= N; i++)
        printf("%d\n", arr[i]);
}