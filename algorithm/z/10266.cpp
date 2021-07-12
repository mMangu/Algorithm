#include <cstdio>
#include <string>

using namespace std;

const int MAX = 360000;

string a, b;
int Z[3 * MAX + 5];

void getZ(const string &str) {
    int L = 0, R = 0;
    int N = str.size();
    for (int i = 1; i < str.size(); i++) {
        if (R < i) {
            L = R = i;
            while (R < N && str[R - L] == str[R]) R++;
            Z[i] = R - L; R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else {
                L = i;
                while (R < N && str[R - L] == str[R]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
}

int main() {
    int N; scanf("%d", &N);
    a.resize(MAX); b.resize(MAX);
    for (int i = 0; i < MAX; i++) a[i] = b[i] = '0';

    for (int i = 0; i < N; i++) {
        int idx; scanf("%d", &idx);
        a[idx] = '1';
    }
    for (int i = 0; i < N; i++) {
        int idx; scanf("%d", &idx);
        b[idx] = '1';
    }
    a += a;
    string concat = b + "$" + a;
    getZ(concat);
    bool flag = false;
    for (int i = 0; i < concat.size(); i++) {
        if (Z[i] >= b.size() - 1) flag = true;
    }
    if (flag) printf("possible");
    else printf("impossible");
}
