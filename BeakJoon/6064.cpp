#include <stdio.h>



int main() {
	int num;
	int M, N, x, y;
	int i, a = 1, b = 1;
	int count = 0;
	int bl = 0;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d%d%d%d", &M, &N, &x, &y);

		b = 1;
		bl = 0;
		count = x;
		b = count % N;
		if (b == 0)
			b = N;
		while (count <= (M*N)) {
			if (x <= 0 || y <= 0)
				break;
			if (b == y)
			{
				bl = 1;
				break;
			}

			b = (b + M) % N;
			if (b == 0) {
				b = N;
			}
			count = count + M;
		}
		if (bl == 1)
		{
			printf("%d\n", count);
		}
		else
		{
			printf("-1\n");
		}
	}
}
