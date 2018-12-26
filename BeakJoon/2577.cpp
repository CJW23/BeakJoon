#include <stdio.h>
#include <string.h>

int main()
{
	int i, a, b, c, d, temp;
	int num[10] = { 0 };
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	d = a*b*c;

	while (1)
	{
		temp = d % 10;
		num[temp]++;
		d = d / 10;
		if (d < 10) {
			num[d]++;
			break;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d\n", num[i]);
	}
}