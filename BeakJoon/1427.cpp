#include <stdio.h>
#include <string.h>

int main()
{
	int a, i, j, temp;
	int st[10], count = 0;
	scanf("%d", &a);

	while (1)
	{
		st[count] = a % 10;
		count++;
		if (a < 10)
		{
			st[count] = a;
			break;
		}
		a = a / 10;
	}
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (st[j] < st[j + 1]) {
				temp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		printf("%d", st[i]);
	}
}