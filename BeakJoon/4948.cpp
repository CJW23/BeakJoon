#include <stdio.h>
int c[1000000];
int main()
{
	int a, b;

	int sum = 0, i, j, count = 0;


	for (i = 2; i*i <= 300000; i++)
	{
		if (c[i] == 1)
			continue;
		for (j = i * 2; j <= 300000; j = j + i) {
			c[j] = 1;
		}
	}

	while (1) {
		scanf("%d", &a);
		if (a == 0)
			break;
		for (i = a + 1; i <= a * 2; i++)
		{

			if (c[i] != 1)
				count++;
		}
		printf("%d\n", count);
		count = 0;
	}
}
