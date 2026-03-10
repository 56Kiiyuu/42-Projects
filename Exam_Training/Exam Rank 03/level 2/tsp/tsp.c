#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct{
	float x, y;
}	City;

float	calcul_distance(City a, City b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float	total_calcul_distance(City *cities, int *path, int n)
{
	float total = 0.0f;
	int	i = 0;

	while (i < n - 1)
	{
		total += calcul_distance(cities[path[i]], cities[path[i + 1]]);
		i++;
	}
	total += calcul_distance(cities[path[n - 1]], cities[path[0]]);
	return (total);
}

void	swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void	find_shortest_path(City *cities, int *path, int n, int pos, float *min_distance)
{
	if (pos == n)
	{
		float current_distance = total_calcul_distance(cities, path, n);
		if (current_distance < *min_distance)
			*min_distance = current_distance;
		return ;
	}
	int i = pos;

	while (i < n)
	{
		swap(&path[pos], &path[i]);
		find_shortest_path(cities, path, n, pos + 1, min_distance);
		swap(&path[pos], &path[i]);
		i++;
	}
}

int main(void)
{
	City cities[12];
	int	n = 0;

	while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;
	if (n < 2)
	{
		printf("0.00\n");
		return (0);
	}
	int	path[12];
	int	i = 0;
	while (i < n)
	{
		path[i] = i;
		i++;
	}

	float min_distance = FLT_MAX;
	find_shortest_path(cities, path, n, 1, &min_distance);
	printf("%.2f", min_distance);
	return (0);
}
