#include <stdio.h>

int main()
{
	int i = 0;
	char s[100];
	while (1)
	{

		if (scanf("%[^\n]s", s) == EOF)
			return 0;

		while (s[i] != NULL)
			i++;
		printf("%s\n", s);
		getchar();
		s[0] = '\0';
	}
	return 0;
}