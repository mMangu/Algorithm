#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int checkRoot(int u[], int v[], int t);
int main(void) {
    int k = 1;
    int u[10000] = { 0, };
    int v[10000] = { 0, };
    int input_u, input_v;
    int t = 0, line = 0, root;
    while (1) {
        for (int i = 0; i < t; i++) {
            u[i] = 0;
            v[i] = 0;
        }
        t = 0;
        line = 0;
        root = 0;
        while (1) {
            scanf("%d %d", &input_u, &input_v);
            if (input_u == 0 && input_v == 0) {
                root = checkRoot(u, v, t);
                if (line == 0 && root == 1 || (t == 0)) // 들어오는 간선 1개, 루트 1개
                    printf("Case %d is a tree.\n", k);
                else
                    printf("Case %d is not a tree.\n", k);
                k++;
                break;
            }
            else if (input_u < 0 && input_v < 0)
                return 0;
            u[t] = input_u;
            v[t] = input_v;
            for (int i = t; i > 0; i--) { //들어오는 간선이 1개 이상인지 확인
                if (v[i - 1] == input_v) {
                    line++;
                }
            }
            for (int i = 0; i <= t; i++) { //나간거에 들어오는거
                if (u[i] == v[i])
                    line++;
            }
            t++;
        }
    }
    return 0;
}
int checkRoot(int u[], int v[], int t) { // 루트 개수 찾는 함수
    int tmp, j = 0, root = 0;
    int arr[1000] = { 0, };
    for (int i = 0; i < t; i++) { //간선 나가는 노드 버블정렬
        for (int j = 0; j < t - 1; j++) {
            if (u[j] > u[j + 1]) {
                tmp = u[j];
                u[j] = u[j + 1];
                u[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < t; i++) { //버블 정렬 한 다음 중복 되는 수 다 없앰
        if (u[i] != u[i + 1]) {
            arr[j] = u[i];
            j++;
        }
    }
    int a = 0;
    for (int i = 0; i < j; i++) { //u에 있는데 v엔 없는거 => 루트 
        a = 0;
        for (int k = 0; k < t; k++) {
            if (v[k] == arr[i])
                a++;
        }
        if (a == 0)
            root++;
    }
    return root;
}