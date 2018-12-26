#include <stdio.h>

int main()
{
	int a, x = 0, y = 0, i = 1, b = 0;
	int tmp;
	scanf("%d", &a);

	if (a < 1 || a>10000000)
		return 0;
	while (1)
	{
		if (a == 1)
			return 0;
		if (x == 0 && y == 0)
		{
			y++;
			i++;
		}
		if (x == 0)
		{
			tmp = y;
			for (b = 0; b < tmp; b++)
			{
				x++;
				y--;
				i++;
				if (i == a)
				{
					printf("%d/%d", x + 1, y + 1);
					return 0;
				}
			}
			x++;
			i++;
			if (i == a)
			{
				printf("%d/%d", x + 1, y + 1);
				return 0;
			}
		}
		else if (y == 0)
		{
			tmp = x;
			for (b = 0; b < tmp; b++)
			{
				x--;
				y++;
				i++;
				if (i == a)
				{
					printf("%d/%d", x + 1, y + 1);
					return 0;
				}
			}
			y++;
			i++;
			if (i == a)
			{
				printf("%d/%d", x + 1, y + 1);
				return 0;
			}
		}

	}
}
