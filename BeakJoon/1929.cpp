#include <stdio.h>
int c[1000000];
int main()
{
	int a, b;

	int sum = 0, i, j, count = 0;

	scanf("%d", &a);
	scanf("%d", &b);

	c[0] = c[1] = 1;
	for (i = 2; i*i <= 1000000; i++)
	{
		if (c[i] == 1)
			continue;
		for (j = i * 2; j <= b; j = j + i) {
			c[j] = 1;
		}
	}

	for (i = a; i <= b; i++)
	{
		if (c[i] != 1)
			printf("%d\n", i);
	}
}