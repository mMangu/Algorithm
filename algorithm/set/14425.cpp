#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    while (N--) {
        string tmp; cin >> tmp;
        s.insert(tmp);
    }
    int ans = 0;
    while (M--) {
        string tmp; cin >> tmp;
        if (s.count(tmp)) ans++;
    }
    cout << ans;
}