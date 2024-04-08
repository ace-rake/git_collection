#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sym;
    int next_to_active;
} t_map;

t_map **map_parse(FILE *file)
{
    t_map **map = malloc(sizeof(t_map *) * 4096);
    char *str = NULL;
    size_t n = 0;

    int height = 0;
    while (getline(&str, &n, file) != -1)
    {
        map[height] = malloc(strlen(str) * sizeof(t_map)); // Corrected allocation
        for (int i = 0; i < strlen(str); i++)
        {
            map[height][i].sym = str[i];
            map[height][i].next_to_active = 0;
        }
        height++;
    }

    free(str); // Free allocated memory for getline
    return map;
}

int main(void)
{
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    t_map **map = map_parse(file);

    // Do something with the map data

    // Don't forget to free the allocated memory when done
    for (int i = 0; i < 4096; i++)
    {
        if (map[i] != NULL)
            free(map[i]);
    }
    free(map);

    fclose(file);
    return 0;
}

