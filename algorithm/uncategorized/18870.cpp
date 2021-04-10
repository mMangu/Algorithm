#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000006];
vector<int> v;

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", arr + i);
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        printf("%d ", idx);
    }
}