#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10000007];

void quicksort(int s, int e) {
    if (s >= e) return;
    int pivot = arr[s], l = s + 1, r = e;
    while (l <= r) {
        while (pivot >= arr[l] && l <= e) l++;
        while (pivot <= arr[r] && r > s) r--;
        if (l <= r) swap(arr[l], arr[r]);
        else swap(arr[s], arr[r]);
    }
    quicksort(s, r - 1);
    quicksort(r + 1, e);
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", arr + i);
    quicksort(0, N - 1);
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
}
