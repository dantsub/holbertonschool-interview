#include "sandpiles.h"
void print_grid_unstable(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_check - check if sandpiles is stable or not
 * @grid1: sandpile to check
 * Return: 0 if sandpiles is stable otherwise -1
 */
int sandpiles_check(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}
/**
 * redistribution_sand - redistribution of sand
 * @grid1: sandpile
 * @i: row index
 * @j: col index
 * Return: Nothing
 */
void redistribution_sand(int grid1[3][3], int i, int j)
{
	int row_t, row_l, row_r, row_b;
	int col_t, col_l, col_r, col_b;

	row_t = i - 1, row_l = i, row_r = i, row_b = i + 1;
	col_t = j - 1, col_l = j, col_r = j, col_b = j + 1;

	grid1[i][j] -= 4;
	if (row_t >= 0 && row_t < 3 && col_t >= 0 && col_t < 3)
		grid1[row_t][col_t] += 1;
	if (row_l >= 0 && row_l < 3 && col_l >= 0 && col_l < 3)
		grid1[row_l][col_l] += 1;
	if (row_r >= 0 && row_r < 3 && col_r >= 0 && col_r < 3)
		grid1[row_r][col_r] += 1;
	if (row_b >= 0 && row_b < 3 && col_b >= 0 && col_b < 3)
		grid1[row_b][col_b] += 1;
}
/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, num = 0, check = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			num = grid1[i][j];
			grid1[i][j] = num + grid2[i][j];
		}
	}
	check = sandpiles_check(grid1);
	while (check)
	{
		print_grid_unstable(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					redistribution_sand(grid1, i, j);
			}
		}
		check = sandpiles_check(grid1);
	}
}
