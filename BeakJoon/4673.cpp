#include <stdio.h>

int d(int n)
{
	int a, b;
	a = n;
	while (n != 0)
	{
		a = a + (n % 10);
		n = n / 10;
	}
	return a;
}

int main()
{
	int a[10001] = { 0, };
	int b, i = 0;


	for (i = 1; i <= 10000; i++)
	{
		if (d(i) <= 10000)
			a[d(i)] = 1;
	}
	for (i = 1; i <= 10000; i++)
	{
		if (a[i] == 0)
			printf("%d\n", i);
	}
}
