#include <unistd.h>
#include <stdlib.h>

int abs_val(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}

void putnbr(int nb)
{
    char c;
    if (nb > 9)
        putnbr(nb / 10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
}
int safe(int *pos, int col, int row)
{
    int i = 0;

    while (i < col)
    {
        if (pos[i] == row)
            return (0);
        if (abs_val(pos[i] - row) == col - i)
            return (0);
        i++;
    }
    return 1;
}

void print_sol(int *pos, int n)
{
    int i = 0;

    while (i < n)
    {
        putnbr(pos[i]);
        if (i + 1 < n)
            write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);
}

void	solve(int *pos, int n, int col)
{
	if (col == n)
	{
		print_sol(pos, n);
		return ;
	}
	int row = 0;
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

int	main(int argc, char **argv)
{
	int	n;
	int	*pos;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	pos = malloc(sizeof(int) * n);
	if (!pos)
		return (1);
	solve(pos, n, 0);
	free(pos);
}