#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

t_map **map_parse(FILE *file)
{
	t_map **map = calloc(sizeof(t_map *), 4096);
	char *str = NULL;
	size_t n = 0;

	int height = 0;
	while (getline(&str, &n, file) != -1)
	{
		map[height] = calloc((strlen(str) + 1), sizeof(t_map *));
		for (int i = 0; i < strlen(str); i++)
		{
			map[height][i].sym = str[i];
			map[height][i].next_to_active = 0;
		}
		height++;
	}
	return (map);
}

void	print_map(t_map **map)
{
	for (int i = 0; map[i] != NULL; i++)
		for (int j = 0; map[i][j].sym != '\0'; j++)
			printf("%c", map[i][j].sym);
}
void	ease_map(t_map **map)
{
	for (int i = 0; map[i] != NULL; i++)
		for (int j = 0; map[i][j].sym != '\0'; j++)
			if (map[i][j].next_to_active != 2)
				map[i][j].sym = ',';
}
void	print_active(t_map **map)
{
	for (int i = 0; map[i] != NULL; i++)
	{
		for (int j = 0; map[i][j].sym != '\0' && map[i][j].sym != '\n'; j++)
			printf("%i", map[i][j].next_to_active);
		printf("\n");
	}
}

int	check(t_map **map, int i, int j)
{
	if (map[i][j].sym == '.' || map[i][j].next_to_active >= 1)
		return (0);
	if (map[i+1] && map[i+1][j].next_to_active >= 1)
		return (1);
	if (map[i][j + 1].sym && map[i][j+1].next_to_active >= 1)
		return (2);
	if (j != 0 &&map[i][j-1].next_to_active >= 1)
		return (3);
	if (i != 0 && map[i-1][j].next_to_active >= 1)
		return (4);
	if (map[i+1] && map[i+1][j+1].next_to_active >= 1)
		return (5);
	if (j != 0 && map[i+1] && map[i+1][j-1].next_to_active >= 1)
		return (6);
	if (i != 0 &&map[i-1][j+1].sym &&  map[i-1][j+1].next_to_active >= 1)
		return (7);
	if (i != 0 && j != 0 && map[i-1][j-1].next_to_active >= 1)
		return (8);
	return (0);
}

void	insert_active_map(t_map **map)
{
	for (int i = 0; map[i] != NULL; i++)
	{
		for (int j = 0; map[i][j].sym != '\0' && map[i][j].sym != '\n'; j++)
		{
			if (map[i][j].sym != '.' && isdigit(map[i][j].sym)==0 && map[i][j].sym != '\n')
				map[i][j].next_to_active = 1;
		}
	}

	int con = 1;
	int retval = 1;


	printf("%i\n", con);
	while (1)
	{
		con = 0;
		for (int i = 0; map[i] != NULL; i++)
		{
			for (int j = 0; map[i][j].sym != '\0' && map[i][j].sym != '\n'; j++)
				{
					retval = check(map, i, j);
					if (retval != 0)
					{
						con++;
						map[i][j].next_to_active = 2;

					}
				}
		}
		if (con == 0)
			break;
	}
}

int	func(t_map **map, int i, int j)
{
	int result = 0;
	while (map[i][j].next_to_active == 2)
	{
		result *= 10;
		result += map[i][j].sym - '0';
		j++;
	}
	return (result);
}

int	main(void)
{
	FILE *file = fopen("text.txt", "r");
	t_map **map = map_parse(file);
	print_map(map);
	insert_active_map(map);
	print_active(map);

	int result = 0;
	int retval;
	for (int i = 0; map[i]; i++)
	{
		printf("line\t%i\t", i+1);
		for (int j = 0; map[i][j].sym != '\n'; j++)
		{
			if (map[i][j].next_to_active == 2 && isdigit(map[i][j].sym) != 0)
			{
				retval = func(map, i, j);
				printf("[%i]", retval);
				result += retval;
				while (map[i][j].next_to_active == 2)
					j++;
			}
		}
			printf("\n");
	}
printf("%i\n", result);	
	

}
