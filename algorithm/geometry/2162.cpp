#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;
using pii = pair<int, int>;

pii a[3003], b[3003];
int par[3003], member_size[3003];

int ccw(pii a, pii b, pii c) {
    int tmp = a.x * b.y + b.x * c.y + c.x * a.y;
    tmp = tmp - (a.y * b.x + b.y * c.x + c.y * a.x);
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    else return 0;
}

bool check(pii a, pii b, pii c, pii d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}

int find(int a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    par[b] = a;
    member_size[a] += member_size[b];
    member_size[b] = 0;
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d %d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
        par[i] = i;
        member_size[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (check(a[i], b[i], a[j], b[j])) {
                merge(i, j);
            }
        }
    }
    int group_num = 0, max_size = 0;
    for (int i = 1; i <= N; i++) {
        if (member_size[i] != 0) {
            group_num++;
            max_size = max(max_size, member_size[i]);
        }
    }
    printf("%d\n%d", group_num, max_size);
}