#include <cstdio>
#include <string>

using namespace std;

int main() {
    int M; scanf("%d", &M);
    int set = 0;
    while (M--) {
        char tmp[10]; scanf("%s", tmp);
        string input = tmp;
        if (input == "add") {
            int num; scanf("%d", &num);
            set |= (1 << (num - 1));
        } else if (input == "remove") {
            int num; scanf("%d", &num);
            set &= ~(1 << (num - 1));

        } else if (input == "check") {
            int num; scanf("%d", &num);
            printf("%d\n", set & (1 << (num - 1)) ? 1 : 0);
        } else if (input == "toggle") {
            int num; scanf("%d", &num);
            set ^= (1 << (num - 1));
        } else if (input == "all") {
            set = 0xfffff;
        } else if (input == "empty") {
            set = 0;
        }
    }
}