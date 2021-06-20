#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
bool visited[10004];

void dfs(int root, int r) {
    if (root == r) return;
    auto idx = upper_bound(v.begin() + root, v.begin() + r, v[root]) - v.begin();
    dfs(root + 1, idx);
    dfs(idx, r);
    cout << v[root] << endl;
}

int main() {
    cin.tie(0);
	ios::sync_with_stdio(0);
    int tmp;
    while (cin >> tmp) v.push_back(tmp);
    dfs(0, v.size());
}