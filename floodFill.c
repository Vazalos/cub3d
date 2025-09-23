#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	flood_fill(int x, int y, char **map)
{
	if (x < 0 || x >= strlen(map[y]) || y < 0 || !map[y] || map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	map[y][x] = 'F';
	if (flood_fill(x - 1, y, map))
		return (1);
	if (flood_fill(x + 1, y, map))
		return (1);
	if (flood_fill(x, y - 1, map))
		return (1);
	if (flood_fill(x, y + 1, map))
		return (1);
	return (0);
}

int	main()
{
	char *map[] = {
	"              ",
    "      11111   ",
    "      10001   ",
    "      10001   ",
    "  111110001   ",
    "  100000001   ",
    "  1000N0001   ",
    "  100000011   ",
    "  11111111    ",
	"              ",
    NULL
	};

	int lines = 10; // number of rows excluding NULL
	char **dup_map = malloc(sizeof(char *) * (lines + 1));
	if (!dup_map)
		return 1;
	for (int i = 0; i < lines; i++)
		dup_map[i] = strdup(map[i]); // each row is writable
	dup_map[lines] = NULL;
	flood_fill(6, 6, dup_map);
	for (int i = 0; dup_map[i]; i++) {
		printf("%s\n", dup_map[i]);
	}
	return (0);
}






