#include <cstdio>
#include <vector>

using namespace std;

pair<int, int> arr[4];

int main() {
    for (int i = 0; i < 3; i++) 
        scanf("%d %d", &arr[i].first, &arr[i].second);
    int cal = (arr[0].first * arr[1].second + arr[1].first * arr[2].second + arr[2].first * arr[0].second) - (arr[0].second * arr[1].first + arr[1].second * arr[2].first + arr[2].second * arr[0].first);
    if (cal > 0) printf("1");
    else if (cal < 0) printf("-1");
    else printf("0");
}