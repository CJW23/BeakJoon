#include <stdio.h>

int main()
{
	int C, N;
	float a[1000], sum = 0, avg, num = 0;
	int i, j;
	scanf("%d", &C);
	for (i = 0; i < C; i++)
	{
		sum = 0;
		num = 0;
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%f", &a[j]);
			sum += a[j];
		}
		avg = sum / N;
		for (j = 0; j < N; j++)
		{
			if (avg < a[j])
				num++;
		}
		printf("%.3f%%\n", (num / N) * 100);

	}

}