#include <stdio.h>

int main()
{
	long long apart[15][15];
	int i, j, test, k, n;

	for (i = 0; i < 15; i++)
		apart[0][i] = i + 1;

	for (i = 1; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (j == 0)
				apart[i][j] = 1;
			else
				apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
		}
	}
	scanf("%d", &test);

	for (i = 0; i < test; i++)
	{
		scanf("%d %d", &k, &n);


		if (k < 1 || n < 1 || k>14 || n > 14)
			return 0;
		printf("%u\n", apart[k][n - 1]);
	}
}
