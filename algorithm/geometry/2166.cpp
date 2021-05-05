#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, double>> v;

double cal(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    return ((a.first * b.second + b.first * c.second + c.first * a.second) - (b.first * a.second + c.first * b.second + a.first * c.second)) / 2;
}

int main() {
    int N; scanf("%d", &N);
    double ans = 0;
    for (int i = 0; i < N; i++) {
        int x, y; scanf("%d %d", &x, &y);
        v.push_back( {x, y} );
    }
    for (int i = 1; i + 1 < N; i++) {
        ans += cal(v[0], v[i], v[i + 1]);
    }
    printf("%.1lf", abs(ans));
}