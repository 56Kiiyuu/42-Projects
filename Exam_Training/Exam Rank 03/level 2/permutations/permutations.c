#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void ft_swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int ft_strchr(char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return (0);
}

char *order_string(char *s)
{
	int len = ft_strlen(s);
	int swapped = 1;

	while (swapped)
	{
		swapped = 0;
		int i = 0;
		while (i < len - 1)
		{
			if (s[i] > s[i + 1])
			{
				ft_swap(&s[i], &s[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
	return (s);
}

void generate_permutations(char *src, char *res, int pos)
{
	int src_len = ft_strlen(src);
	if (pos == src_len)
	{
		write(1, res, src_len);
		write(1, "\n", 1);
		return ;
	}
	int i = 0;
	while (i < src_len)
	{
		if (!ft_strchr(res, src[i]))
		{
			res[pos] = src[i];
			generate_permutations(src, res, pos + 1);
			res[pos] = '\0';
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	if (ft_strlen(argv[1]) == 0 || (argv[1][0] == ' ' && !argv[1][1]))
		return 0;
	int i = 0;
	while (argv[1][i])
	{
		if (!ft_isalpha(argv[1][i]))
			return 0;
		i++;
	}
	int len = ft_strlen(argv[1]);
	char *res = calloc(len + 1, 1);
	if (!res)
		return 1;
	char *src = order_string(argv[1]);
	generate_permutations(src, res, 0);
	free(res);
	return (0);
}
