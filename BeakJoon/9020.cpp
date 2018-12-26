#include <stdio.h>
int c[1000000];
int total[10000];
int main()
{
	int a, b, num = 0, k;
	int temp = 10000000, temp1, temp2;
	int sum = 0, i, j, count = 0;


	for (i = 2; i*i <= 10000; i++)
	{
		if (c[i] == 1)
			continue;
		for (j = i * 2; j <= 10000; j = j + i) {
			c[j] = 1;
		}
	}


	scanf("%d", &a);
	for (i = 0; i < a; i++)
	{
		scanf("%d", &b);
		for (k = j = b / 2; k > 1; k--, j++)
		{
			if (c[k] != 1 && c[j] != 1)
			{
				printf("%d %d\n", k, j);
				break;

			}
		}
	}
}
