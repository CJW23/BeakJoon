#include <stdio.h>

int main()
{
	int M, N;
	int i;
	float score[1000], max = 0, avg, sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%f", &score[i]);

	for (i = 0; i < N; i++)
	{
		if (max < score[i])
			max = score[i];
	}
	for (i = 0; i < N; i++)
	{
		score[i] = (score[i] / max) * 100;
		sum += score[i];
	}
	avg = sum / N;
	printf("%.2f", avg);

}