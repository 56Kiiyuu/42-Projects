#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

int ft_issalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*order_string(char *s)
{
	int swapped = 1;
	int len = ft_strlen(s);

	while (swapped)
	{
		swapped = 0;
		int i = 0;
		while (i < len - 1)
		{
			if(s[i] > s[i + 1])
			{
				ft_swap(&s[i], &s[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
	return (s);
}

void	gen_permut(char *src, char *res, int pos)
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
			gen_permut(src, res, pos + 1);
			res[pos] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) == 0)
		return (0);
	int i = 0;
	while (argv[1][i])
	{
		if (!ft_issalpha(argv[1][i]))
			return (1);
		i++;
	}
	int len = ft_strlen(argv[1]);
	char *res = calloc(len + 1, 1);
	if (!res)
		return (1);
	char *src = order_string(argv[1]);
	gen_permut(src, res, 0);
	free(res);
	return (0);
}
