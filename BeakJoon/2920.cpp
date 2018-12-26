#include <stdio.h>
#include <string.h>


int main()
{
	int a[8], count1 = 0, count2 = 0;
	int i;
	for (i = 0; i < 8; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < 8; i++)
	{
		if (a[i] != i + 1 && a[i] != 8 - i)
		{
			break;
		}
		else if (a[i] == i + 1) {
			count1++;
		}
		else if (a[i] == 8 - i) {
			count2++;
		}
	}

	if (count1 == 8) {
		printf("ascending");
	}
	else if (count2 == 8) {
		printf("descending");
	}
	else {
		printf("mixed");
	}
}