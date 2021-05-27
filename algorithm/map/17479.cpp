#include <iostream>
#include <map>
#include <string>

using namespace std;
using ll = long long;

map<string, ll> normal, special, service; 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int A, B, C; cin >> A >> B >> C;
    for (int i = 0; i < A; i++) {
        string menu; ll price; cin >> menu >> price;
        normal.insert({menu, price});
    }
    for (int i = 0; i < B; i++) {
        string menu; ll price; cin >> menu >> price;
        special.insert({menu, price});
    }
    for (int i = 0; i < C; i++) {
        string menu; cin >> menu;
        service.insert({menu, 0});
    }
    ll normalTotal = 0, specialTotal = 0, serviceCnt = 0;
    int N; cin >> N;
    while (N--) {
        string ipt; cin >> ipt;
        auto iter = normal.find(ipt);
        if (iter != normal.end()) {
            normalTotal += iter->second;
        }

        iter = special.find(ipt);
        if (iter != special.end()) {
            specialTotal += iter->second;
        }

        iter = service.find(ipt);
        if (iter != service.end()) {
            serviceCnt++;
        }        
    }
    bool flag = true;
    if (specialTotal > 0 && normalTotal < 20000) flag = false;
    else if (serviceCnt > 0 && specialTotal + normalTotal < 50000) flag = false;
    else if (serviceCnt > 1) flag = false;
    if (flag) cout << "Okay";
    else cout << "No";
}