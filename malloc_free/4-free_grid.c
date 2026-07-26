#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2D grid.
 * @grid: Grid to free.
 * @height: Number of rows.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
