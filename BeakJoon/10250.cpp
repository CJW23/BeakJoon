#include <stdio.h>

int main()
{
	int test, N, H, W, location;
	int i;
	scanf("%d", &test);

	for (i = 0; i < test; i++)
	{
		scanf("%d %d %d", &H, &W, &N);

		if (H < 0 || H>99 || W < 0 || W>99 || N < 1 || N > H*W)
			return 0;
		if (N%H == 0)
			printf("%d%02d\n", H, N / H);
		else
			printf("%d%02d\n", N % H, N / H + 1);
	}
}
