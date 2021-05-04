#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int tree[30][2];

void preOrder(int n) {
    if (n == -1) return;
    printf("%c", n + 'A');
    preOrder(tree[n][0]);
    preOrder(tree[n][1]);
}

void inOrder(int n) {
    if (n == -1) return;
    inOrder(tree[n][0]);
    printf("%c", n + 'A');
    inOrder(tree[n][1]);
}

void postOrder(int n) {
    if (n == -1) return;
    postOrder(tree[n][0]);
    postOrder(tree[n][1]);
    printf("%c", n + 'A');
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char a, b, c; cin >> a >> b >> c;
        tree[a - 'A'][0] = b == '.' ? -1 : b - 'A';
        tree[a - 'A'][1] = c == '.' ? -1 : c - 'A';
    }
    preOrder(0);
    printf("\n");
    inOrder(0);
    printf("\n");
    postOrder(0);
}