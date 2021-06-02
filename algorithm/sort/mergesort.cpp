#include <cstdio>

int sorted[10000007], unsorted[10000007];


void merge(int s, int e) {
    int mid = (s + e) / 2;
    int left = s, right = mid + 1, idx = s;
    while (left <= mid && right <= e) {
        if (unsorted[left] <= unsorted[right]) sorted[idx++] = unsorted[left++];
        else sorted[idx++] = unsorted[right++];
    }
    if (right > e) {
        for (int i = left; i <= mid; i++) sorted[idx++] = unsorted[i];
    } else {
        for (int i = right; i <= e; i++) sorted[idx++] = unsorted[i];
    }
    for (int i = s; i <= e; i++) unsorted[i] = sorted[i];
}

void mergeSort(int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        mergeSort(s, mid);
        mergeSort(mid + 1, e);
        merge(s, e); 
    }   
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", unsorted + i);
    mergeSort(0, N - 1);
    for (int i = 0; i < N; i++) printf("%d ", unsorted[i]);
}