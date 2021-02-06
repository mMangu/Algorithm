#include <cstdio>
int main(void) {
	int N, L, K;
	int sub1[102],sub2[102];
	int grade = 0,correct = 0;
	scanf("%d %d %d", &N, &L, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &sub1[i], &sub2[i]);
	}
	for (int i = 0; i < N; i++) {
		if (correct == K) {
			printf("%d", grade);
			return 0;
		}
		if (sub2[i] <= L) {
			grade += 140;
			correct++;
			}
	}
	for (int i = 0; i < N; i++) {
		if (correct == K) {
			printf("%d", grade);
			return 0;
		}
		if (sub2[i] > L && sub1[i] <= L) {
			grade += 100;
			correct++;
			}
	}
	printf("%d", grade);
	return 0;
}