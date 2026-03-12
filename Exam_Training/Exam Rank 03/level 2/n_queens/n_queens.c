#include <stdlib.h>
#include <stdio.h>

int abs_val(int n)
{
	if (n < 0)
		return (-n);
	return(n);
}
int safe(int *pos, int col, int row)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (pos[i] == row)
			return (0);
		if (abs_val(pos[i] - row) == col - i)
			return (0);
		i++;
	}
	return (1);
}

void print_sol(int *pos, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%d", pos[i]);
		if (i + 1 < n)
			printf(" ");
		i++;
	}
	printf("\n");
}

void solve(int *pos, int n, int col)
{
	int row;

	if (col == n)
	{
		print_sol(pos, n);
		return;
	}
	row = 0;
	while (row < n)
	{
		if (safe(pos, col, row))
		{
			pos[col] = row;
			solve(pos, n, col + 1);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	int n;
	int *pos;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	pos = malloc(sizeof(int) * n);
	solve(pos, n, 0);
	free(pos);
}
