#include <stdio.h>
int main() {
	int a, b = 0, i;
	scanf("%d", &a);
	if (a < 3 || a>5000)
		return 0;
	for (i = a / 5; i >= 0; i--)
		if ((a - (i * 5)) % 3 == 0) {
			b = i + (a - (i * 5)) / 3; printf("%d", b); return 0;
		}printf("-1");
}