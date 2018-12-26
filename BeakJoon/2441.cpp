#include <stdio.h>

int main()
{
	int a;
	int i, j, k;
	scanf("%d", &a);

	if (a > 100 || a < 1)
		return 0;
	for (i = a; i > 0; i--)
	{
		for (k = 0; k<a - i; k++)
			printf(" ");
		for (j = a - i; j < a; j++)
			printf("*");

		printf("\n");
	}
}
