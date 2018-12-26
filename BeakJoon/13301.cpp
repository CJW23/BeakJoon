#include <stdio.h>

int main()
{
	unsigned long long fibo[81], value = 6, i, up = 6;
	int num = 1, N;

	fibo[0] = 1;
	fibo[1] = 1;
	for (i = 2; i < 81; i++)
	{
		fibo[i] = fibo[i - 2] + fibo[i - 1];
		//printf("%llu\n", fibo[i]);
	}
	scanf("%d", &N);
	if (N < 1 || N>80)
		return 0;

	if (N == 1)
	{
		printf("4");
		return 0;
	}
	if (N == 2)
	{
		printf("6");
		return 0;
	}
	for (i = 2; i < N; i++)
	{
		up = up + fibo[i - 2] + fibo[i - 1] + fibo[i];
	}
	printf("%llu", up);

}
