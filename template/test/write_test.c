#include <stdlib.h>
int	main(void)
{
	char *str = malloc (sizeof(char) * 2);
	for (int i = 0; i < 500; ++i)
		str[i] = 'a';
	free(str);
	return (0);
}
