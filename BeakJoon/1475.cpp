#include <stdio.h>
#include <string.h>

int main()
{
	int input;
	int i;
	int a;
	int b[10] = { 0, };
	int count = 0;
	scanf("%d", &input);

	while (1) {
		a = input % 10;
		b[a]++;
		if (input < 10)
			break;
		input = input / 10;
	}

	for (i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			if ((b[6] + b[9]) % 2 == 1) {
				if (((b[6] + b[9]) / 2 + 1) > count)
					count = ((b[6] + b[9]) / 2 + 1);
			}
			else {
				if ((b[6] + b[9]) / 2 > count)
					count = (b[6] + b[9]) / 2;
			}
		}
		else if (b[i] > count)
			count = b[i];
	}
	printf("%d", count);
}