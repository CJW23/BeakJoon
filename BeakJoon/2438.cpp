#include <stdio.h>

int main()
{
	int a;
	int i, j;
	scanf("%d", &a);

	if (a > 100 || a < 1)
		return 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
}
