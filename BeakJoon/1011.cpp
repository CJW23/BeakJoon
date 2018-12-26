#include <stdio.h>
#include <math.h>

int main()
{
	int a, i = 0, s;
	long long  x, y, mid = 1, tmp, correct;


	scanf("%d", &a);


	for (s = 0; s < a; s++)
	{
		scanf("%u %u", &x, &y);
		/*if (x >= y || x < 0 || y > 2147483647 || x > 2147483647 || y < 0)
		return 0;*/
		mid = sqrt(y - x);

		while (1)
		{
			tmp = y - x;
			if (tmp >(mid*mid) - mid && tmp <= (mid*mid))
			{
				correct = (2 * mid) - 1;
				printf("%d\n", correct);
				break;
			}
			else if (tmp > (mid*mid) && tmp <= (mid*mid) + mid)
			{
				correct = (2 * mid);
				printf("%d\n", correct);
				break;
			}
			mid++;
		}
	}
}
