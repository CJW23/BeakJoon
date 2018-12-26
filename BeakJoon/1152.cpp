#include <stdio.h>
#include <string.h>

int main()
{
	char s1[1000000];
	int a = 0;
	char *ptr;
	fgets(s1, 1000000, stdin);

	ptr = strtok(s1, " ");
	while (ptr != NULL)
	{

		if (strcmp(ptr, "\n") && strcmp(ptr, " ")) {
			a++;
		}
		ptr = strtok(NULL, " ");
	}
	printf("%d", a);
}