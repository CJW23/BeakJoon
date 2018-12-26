#include <stdio.h>

int main()
{

	int a = 0;
	int b = 0;
	int i;
	scanf("%d", &a);
	if (a > 10000 || a < 1)
		return 0;

	for (i = 1; i <= a; i++)
		b += i;

	printf("%d", b);
}
