#include <stdio.h>

int main()
{
	int a, b, c, d, i;

	scanf("%d", &a);

	if (a < 1 || a>1000000000)
		return 0;
	b = 2;
	c = 4;
	d = 0;
	while (1)
	{
		if (a == 1)
		{
			printf("%d", a);
			return 0;
		}
		if (a < (b*c - d))
		{
			printf("%d", b);
			return 0;
		}
		b++;
		c += 3;
		d++;
	}
}
