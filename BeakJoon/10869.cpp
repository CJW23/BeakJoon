#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	if (a <= 0)
		return 0;
	if (b > 10000)
		return 0;

	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d\n", a % b);
}