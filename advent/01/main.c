#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
int	check_full(char *str)
{
	if (strncmp(str, "one", 3) == 0)
		return (1);
	if (strncmp(str, "two", 3) == 0)
		return (2);
	if (strncmp(str, "three", 5) == 0)
		return (3);
	if (strncmp(str, "four", 4) == 0)
		return (4);
	if (strncmp(str, "five", 4) == 0)
		return (5);
	if (strncmp(str, "six", 3) == 0)
		return (6);
	if (strncmp(str, "seven", 5) == 0)
		return (7);
	if (strncmp(str, "eight", 5) == 0)
		return (8);
	if (strncmp(str, "nine", 4) == 0)
		return (9);
	return (0);
}

int	func(char *str)
{
	char str_result[3];
	int i = 0;
	str_result[2] = '\0';

	while (isdigit(str[i]) == 0 && str[i] != '\n' && check_full(&str[i]) == 0)
		++i;
	if (isdigit(str[i]))
		str_result[0] = str[i];
	else
		str_result[0] = check_full(&str[i]) + '0';
	while (str[++i]);
	--i;
	--i;
	while ((isdigit(str[i]) == 0) && i >= 0 && check_full(&str[i]) == 0)
		--i;
	if (isdigit(str[i]))
		str_result[1] = str[i];
	else
		str_result[1] = check_full(&str[i]) + '0';
	printf("found str [%s]\n", str_result);
	return (atoi(str_result));
}

int	main(void)
{
	FILE *file = fopen("text.txt", "r");	
	int	result = 0;
	char *str;
	str = NULL;
		
	size_t n = 0;
	while (getline(&str, &n ,file) != -1)
	{
		printf("%s", str);
		result += func(str);
		printf ("%i\n", result);
	}
	printf("%i\n", result);
}
