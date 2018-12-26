#include <stdio.h>

int main()
{
	int a;
	int i;
	scanf("%d", &a);

	if (a > 10 || a < 1)
		return 0;
	for (i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", a, i, a*i);
	}
}
