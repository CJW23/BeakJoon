#include <stdio.h>

int main()
{
	int N;
	int a, b, c = -1, d, temp, count = 0;

	scanf("%d", &N);

	if (N > 99 || N < 0)
		return 0;

	temp = N;
	while (c != N)
	{
		a = temp / 10;
		b = temp % 10;
		if ((a + b) >= 10)
			d = (a + b) % 10;
		else
			d = a + b;
		c = (b * 10) + d;
		count++;
		temp = c;
	}
	printf("%d", count);
}