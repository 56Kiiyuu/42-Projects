#define _GNU_SOURCE
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void ft_filter(char *buffer, const char *target)
{
	int	i = 0;
	int	target_len = strlen(target);
	int	j, k;

	while (buffer[i])
	{
		j = 0;
		while (buffer[j] && (buffer[i + j] == target[j]))
			j++;
		if (j == target_len)
		{
			k = 0;
			while (k < target_len)
			{
				write(1, "*", 1);
				k++;
			}
			i += target_len;
		}
		else
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	char	temp[BUFFER_SIZE];
	char	*res = NULL;
	char	*buffer;
	int		total_read = 0;
	ssize_t	bytes;

	while ((bytes = read(0, temp, BUFFER_SIZE)) > 0)
	{
		buffer = realloc(res, total_read + bytes + 1);
		if (!buffer)
		{
			free(res);
			perror("realloc");
			return (1);
		}
		res = buffer;
		memmove(res + total_read, temp, bytes);
		total_read += bytes;
		res[total_read] = '\0';
	}
	if (bytes < 0)
	{
		perror("read");
		free(res);
		return (1);
	}
	if (!res)
		return (0);
	ft_filter(res, argv[1]);
	free(res);
	return (0);
}
