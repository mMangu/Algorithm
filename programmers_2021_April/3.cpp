//fail code
#include <string>
#include <vector>

using namespace std;
vector<int> v[300005];

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    int sum = 0;
    for (int i = 0; i < a.size(); i++) sum += a[i];
    if (sum) return -1;
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i][0], y = edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while (1) {
        for (int i = 0; i < edges.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (a[v[i][j]] != 0) cnt++;
            }
        }
    }
    return answer;
}