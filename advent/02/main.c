#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//

int	is_possible(char *str)
{
	int id;
	int result;
	int block[3] = {0, 0, 0};

	while (isdigit(*str) == 0)
		str++;
	id = atoi(str);
	while (isdigit(*str) != 0)
		str++;
	while (*str)
	{
			while (*str && isdigit(*str) == 0)
				str++;
			result = atoi(str);
			while (*str && isalpha(*str) == 0)
				str++;
			if (strncmp(str, "red", 3) == 0)
			{
				if (result > block[0])
					block[0] = result;
			}
			else if (strncmp(str, "green", 5) == 0)
			{	
				if (result > block[1])
					block[1] = result;
			}	
			else if (strncmp(str, "blue", 4) == 0)
			{
				if (result > block[2])
					block[2] = result;
			}
	}
	printf("max red [%i] : max green [%i]: max blue [%i]\n", block[0], block[1], block[2]);
	if (block[0] > 12 || block[1] > 13 || block[2] > 14)
		return (-1);
	else
		return (id);
}

int	main(void)
{
	FILE *file = fopen("text.txt", "r");

	char *str = NULL;
	size_t n = 0;

	int retval = 0;
	int result = 0;
	while (getline(&str, &n, file) != -1)
	{
		retval = is_possible(str);
//		printf("in string [%s] gave return [%i]\n", str, retval);
		if (retval != -1)
			result += retval;
		printf("retval [%i] : new result [%i]\n", retval, result);
	}
	printf("[%i]\n", result);
}
