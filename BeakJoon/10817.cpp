#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a < 1 || b < 1 || c < 1 || a>100 || b>100 || c>100)
		return 0;
	if (a > b)
	{
		if (a <= c)
			printf("%d", a);
		else if (b >= c)
			printf("%d", b);
		else
			printf("%d", c);
	}
	else
	{
		//a<b
		if (b <= c)
			printf("%d", b);
		else if (a >= c)
			printf("%d", a);
		else
			printf("%d", c);
	}
}
