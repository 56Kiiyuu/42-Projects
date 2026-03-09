#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    int i = 0;
    if (!s)
        return NULL;
    while (s[i])
    {
        if (s[i] == c)
            return &s[i];
        i++;
    }
    if (c == '\0')
        return &s[i];
    return NULL;
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return i;
}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0, j = 0;
    char *res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return NULL;
    while (s1 && s1[i])
        res[j++] = s1[i++];
    i = 0;
    while (s2 && s2[i])
        res[j++] = s2[i++];
    res[j] = 0;
    free(s1);
    return res;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char *line = NULL;
    char *tmp;
    int r;

    while (!(tmp = ft_strchr(buf, '\n')))
    {
        line = ft_strjoin(line, buf);
        r = read(fd, buf, BUFFER_SIZE);
        if (r <= 0)
		{
		    if (!line || *line == 0)
			{
				free(line);
		        return NULL;
			}
		    buf[0] = 0;
		    return line;
		}
        buf[r] = 0;
    }
    *tmp = 0;
    line = ft_strjoin(line, buf);
    int i = 0;
	while (buf[i + (tmp - buf) + 1])
	{
    	buf[i] = buf[i + (tmp - buf) + 1];
    	i++;
	}
	buf[i] = 0;
    return line;
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Use: %s <file>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error: cannot open file");
        return 1;
    }

    char *line;
    int count = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s\n", count + 1, line);
		free(line);
		count++;
	}

    close(fd);
    return 0;
}*/
