#include <stdio.h>

int main()
{
	int x, y;

	int i, j;
	int week = 0;
	scanf("%d %d", &x, &y);

	if (x < 1 || x>12)
		return 0;
	if (y < 1 || y>31)
		return 0;
	if (x == 4 || x == 6 || x == 9 || x == 11)
		if (y > 30)
			return 0;
	if (x == 2)
		if (y > 28)
			return 0;

	for (i = 1; i < x; i++)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
			week = (week + 30) % 7;
		else if (i == 2)
			week = (week + 28) % 7;
		else
			week = (week + 31) % 7;
	}
	for (i = 1; i <= y; i++)
		week = week + 1;
	week = week % 7;
	switch (week)
	{
	case 0:
		printf("SUN");
		break;
	case 1:
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	}
}
