#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr;
int g[555][555];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        memset(g, 0, sizeof g);
        int n; scanf("%d", &n);
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                g[arr[i]][arr[j]] = 1;
            }
        }
        int m; scanf("%d", &m);
        while (m--) {
            int a, b; scanf("%d %d", &a, &b);
            swap(g[a][b], g[b][a]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[arr[j]][arr[i]]) swap(arr[i], arr[j]);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (g[arr[j]][arr[i]]){
                    printf("IMPOSSIBLE\n");
                    return 0;
                }
            }
        }
        for (auto i : arr) printf("%d ", i);
        printf("\n");
    }
}