#include <stdio.h>

int main()
{
	int a, b;
	int c[100], check = 0, min;
	int sum = 0, i, j, count = 0;
	scanf("%d", &a);
	scanf("%d", &b);

	for (i = a; i <= b; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i%j == 0)
				count++;
		}
		if (count == 2)
		{
			sum = sum + i;
			if (check == 0)
			{
				min = i;
				check = 1;
			}
		}
		count = 0;
	}
	if (sum != 0)
		printf("%d\n%d", sum, min);
	else
		printf("-1");
}