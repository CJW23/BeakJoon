#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a <= 1)
		return 0;
	if (b > 10000)
		return 0;
	if (c > 10000)
		return 0;

	printf("%d\n", (a + b) % c);
	printf("%d\n", ((a%c) + (b%c)) % c);
	printf("%d\n", (a*b) % c);
	printf("%d\n", ((a%c)*(b%c)) % c);
}