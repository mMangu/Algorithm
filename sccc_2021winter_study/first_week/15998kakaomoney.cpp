#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
using ll = long long;
ll a[300005];
ll b[300005];
ll key[300005];
ll GCD(ll, ll);
int main(void) {
	int N, k = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		if (i == 0 && a[i] < 0) {
			key[k++] = b[i] - a[i];
		}
		if (i - 1 >= 0 && a[i] + b[i - 1] < 0) {
			key[k++] = b[i] - a[i] - b[i - 1];
		}
	}
	if (a[0] > 0 && a[0] != b[0]) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i < N; i++) {
		if (a[i] + b[i - 1] > 0 && b[i - 1] + a[i] != b[i]) {
			printf("-1");
			return 0;
		}
	}
	if (k == 0) {
		printf("1");
		return 0;
	}
	if (k == 1) {
		printf("%lld", key[0]);
		return 0;
	}
	ll M = 0;
	for (int i = 0; i < k; i++) {
		M = GCD(M, key[i]);
	}

	if (a[0] < 0 && b[0] >= M) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i < N; i++) {
		if (a[i] + b[i - 1] < 0 && b[i] >= M) {
			printf("-1");
			return 0;
		}
	}
	printf("%lld", M);
	return 0;
}

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}