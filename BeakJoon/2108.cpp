#include <stdio.h>
int a[4001];
int b[4001];

int main() {
	int num, i, j, c, arng, maxmanynum;
	int chk = 0, sum = 0, mid = 0, midnum, min = -9000, max = 0, maxmany = 0, count = 0, temp;
	float avg;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &c);
		if (c < 0)
			a[(-1 * c)]++;
		else
			b[c]++;
	}
	num = num / 2 + 1;	//Áß¾ÓÀÇ ¼ýÀÚ
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (j = 4000; j > 0; j--)
			{
				sum = sum + (-1 * j)*a[j];
				if (mid<num && (mid + a[j]) >= num) {
					midnum = (-1 * j);		//Áß¾Ó°ª
					mid = mid + a[j];
				}
				else
				{
					mid = mid + a[j];
				}
				if (a[j] > 0 && chk == 0)
				{
					min = (-1 * j);
					chk = 1;
				}
				if (a[j] > 0)
					max = (-1 * j);
				if (a[j] > maxmany)
					maxmany = a[j];
			}
		}
		else
		{
			for (j = 0; j <= 4000; j++)
			{
				sum = sum + j*b[j];
				if (mid<num && (mid + b[j]) >= num) {
					midnum = j;		//Áß¾Ó°ª
					mid = mid + b[j];
				}
				else
				{
					mid = mid + b[j];
				}
				if (b[j] > 0 && chk == 0)
				{
					min = j;
					chk = 1;
				}
				if (b[j] > 0)
					max = j;
				if (b[j] > maxmany)
					maxmany = b[j];
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (j = 4000; j > 0; j--)
			{
				if (a[j] == maxmany && count == 0)
				{
					temp = (-1 * j);
					count++;
				}
				else if (a[j] == maxmany && count == 1)
				{
					maxmanynum = (-1 * j);
					count++;
					break;
				}
				if (j == 4000 && count == 1)
					maxmanynum = temp;
			}
		}
		else
		{
			for (j = 0; j <= 4000; j++)
			{
				if (b[j] == maxmany && count == 0)
				{
					temp = j;
					count++;
				}
				else if (b[j] == maxmany && count == 1)
				{
					maxmanynum = j;
					count++;
					break;
				}
				if (j == 4000 && count == 1)
					maxmanynum = temp;
			}
		}
		if (count == 2)
			break;
	}

	avg = (float)sum / ((num * 2) - 1);
	arng = max - min;

	printf("%.0f\n", avg);
	printf("%d\n", midnum);
	printf("%d\n", maxmanynum);
	printf("%d\n", arng);
}

