#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * add_grid - Adds grid2 to grid1
 * @grid1: Grid that will have 'grid2' added to it.
 * @grid2: Grid that will be added to 'grid1'
 *
 * Return: void, result is in 'grid1'
 */
void add_grid(int grid1[3][3], int grid2[3][3])
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		size_t j;

		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * copy_grid - Copies 'source_grid' into 'destination_grid'
 * @source_grid: The grid to copy into 'destination_grid'
 * @destination_grid: The grid that will be transformed into
 * a copy of 'source_grid'
 *
 * Return: nothing, 'destination_grid' is modified
 */
void copy_grid(int source_grid[3][3], int destination_grid[3][3])
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		size_t j;

		for (j = 0; j < 3; j++)
		{
			destination_grid[i][j] = source_grid[i][j];
		}
	}
}

/**
 * copy_and_topple - Simulates a toppling round
 * @current_grid: POINTER TO grid that
 * will be toppled
 * @future_grid: POINTER TO a grid
 * that will be toppled
 * Return: true if 'current_grid' was stable,
 * false if 'current_grid' wasn't stable.
 */
bool copy_and_topple(int current_grid[3][3], int future_grid[3][3])
{
	size_t i, j;
	bool current_grid_was_stable = true;

	copy_grid(current_grid, future_grid);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (current_grid[i][j] > 3)
			{
				current_grid_was_stable = false;

				future_grid[i][j] -= 4;

				if (i > 0)
					future_grid[i - 1][j]++;
				if (i < 2)
					future_grid[i + 1][j]++;
				if (j > 0)
					future_grid[i][j - 1]++;
				if (j < 2)
					future_grid[i][j + 1]++;
			}
		}
	}

	return (current_grid_was_stable);
}

/**
 * sandpiles_sum - Simulates a round of toppling sandpiles
 * @grid1: The grid which will have the sandpiles from the
 * other grid dumped on it
 * @grid2: The grid of sandpiles to dump on 'grid1'
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grid(grid1, grid2);

	do {
		int future_grid[3][3];

		bool grid1_was_stable = copy_and_topple(grid1, future_grid);

		if (grid1_was_stable)
			break;

		puts("=");
		print_grid(grid1);

		copy_grid(future_grid, grid1);
	} while (true);
}
