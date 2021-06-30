#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double sqare(double a) {
    return a * a;
}
int main() {
    double x1, y1, r1, x2, y2, r2; scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }   
    double d = sqrt(sqare(x1 - x2) + sqare(y1 - y2));
    if (d >= r1 + r2) {
        printf("0.000");
    } else if (d + r2 <= r1) {
        printf("%.3lf", r2 * r2 * acos(-1));
    } else {
        double theta1 = acos((sqare(r1) + sqare(d) - sqare(r2)) / (2 * r1 * d));
        double theta2 = acos((sqare(r2) + sqare(d) - sqare(r1)) / (2 * r2 * d));
        double s1 = (r1 * r1 * theta1) - (r1 * r1 * sin(2 * theta1)) / 2;
        double s2 = (r2 * r2 * theta2) - (r2 * r2 * sin(2 * theta2)) / 2;
        printf("%.3lf", s1 + s2);
    }
}