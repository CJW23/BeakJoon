#include <stdio.h>

int main() {
	int a[1000];
	int b, c;
	int i, j;
	int temp;
	scanf("%d", &b);

	for (i = 0; i < b; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < b; i++) {
		for (j = 0; j < b - i - 1; j++) {
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < b; i++) {
		printf("%d\n", a[i]);
	}
}
