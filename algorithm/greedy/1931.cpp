#include <cstdio>
#include <algorithm>

using namespace std;
pair<int, int> arr[100005];
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d %d",&arr[i].second, &arr[i].first);
    sort(arr, arr + N);
    int tmp = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].second >= tmp) {
            cnt++;
            tmp = arr[i].first;
        }
    }
    printf("%d",cnt);
}