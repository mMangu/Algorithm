#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int x, y, d, t; scanf("%d %d %d %d", &x, &y, &d, &t);
    double dist = sqrt(x * x + y * y);
    int jump = dist / d;
    double remain = dist - jump * d;
    //그냥 걷는 경우, 점프 하고 남은 거리 걷는 경우
    double ans = min(dist, remain + jump * t);
    //(0, 0) 넘어서까지 점프하고 뒤로 걷는 경우
    ans = min(ans, (jump + 1) * d - dist + (jump + 1) * t);
    if (jump > 0) {
        //방향 꺾어서 점프만 하는 경우
        ans = min(ans, double(jump + 1) * t);
    } else {
        //점프만 두번 하는 경우
        if (dist < d) ans = min(ans, t * 2.0);
    }
    printf("%.9lf", ans);
}