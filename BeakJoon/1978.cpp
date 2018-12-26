#include <stdio.h>

int main()
{
	int a, b[100], c[100], i, j;
	int count = 0, num = 0;
	scanf("%d", &a);

	for (i = 0; i < a; i++)
		scanf("%d", &b[i]);

	for (i = 0; i < a; i++)
	{
		for (j = 1; j <= b[i]; j++)
		{
			if (b[i] % j == 0)
				count++;
		}
		if (count == 2)
			num++;
		count = 0;
	}
	printf("%d", num);
}