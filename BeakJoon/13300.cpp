#include <stdio.h>

int main()
{
	int num[6][2] = { 0 }; int a, b, room = 0; int i, j; scanf("%d %d", &a, &b);
	if (a > 1000 || a < 1 || b>1000 || b < 1)
		return 0;
	for (i = 0; i < a; i++) {
		int c, d;
		scanf("%d %d", &c, &d);
		if (d > 6 || d < 1 || (c != 0 && c != 1))
			return 0; num[d - 1][c] += 1;
	}
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 2; j++) {
			if (num[i][j] != 0) {
				room = room + (num[i][j] / b);
				if (num[i][j] % b != 0)
					room += 1;
			}
		}
	}printf("%d", room);
}