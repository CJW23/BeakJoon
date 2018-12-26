#include <stdio.h>
#include <string.h>


int main()
{
	char test[80];
	int a = 0;
	int i, num, count = 0, score = 0;
	int j = 0;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%s", test);
		while (test[j] != NULL) {
			if (test[j] == 'O') {
				++count;
				score += count;
				test[j] = '\0';
				j++;

			}
			else {
				count = 0;
				test[j] = '\0';
				j++;

			}
		}
		printf("%d\n", score);
		score = 0;
		count = 0;
		j = 0;

	}

}