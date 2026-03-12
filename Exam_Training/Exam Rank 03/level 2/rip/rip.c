#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int is_balanced(char *str, int len)
{
	int balance = 0;
	int i = 0;

	while (i < len)
	{
		if (str[i] == '(')
			balance++;
		else if (str[i] == ')')
		{
			balance--;
			if (balance < 0)
				return 0;
		}
		i++;
	}
	return (balance == 0);
}

void	find_min_removals(char *str, int *min_removals, int index, int current_removals)
{
	if (current_removals > *min_removals)
		return ;
	if (is_balanced(str, ft_strlen(str)))
	{
		if (current_removals < *min_removals)
			*min_removals = current_removals;
		return ;
	}
	int i = index;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			char tmp = str[i];
			str[i] = ' ';
			find_min_removals(str, min_removals, i + 1, current_removals + 1);
			str[i] = tmp;
		}
		i++;
	}
}

void	gen_solutions(char *str, int min_removals, int index, int current_removals)
{
	if (current_removals > min_removals)
		return ;
	if (is_balanced(str, ft_strlen(str)) && current_removals == min_removals)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		return ;
	}
	int i = index;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			char tmp = str[i];
			str[i] = ' ';
			gen_solutions(str, min_removals, i + 1, current_removals + 1);
			str[i] = tmp;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if(argc != 2 || argv[1][0] == '\0')
		return (1);
	int i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != '(' && argv[1][i] != ')')
			return (1);
		i++;
	}
	int min_removals = ft_strlen(argv[1]);
	find_min_removals(argv[1], &min_removals, 0, 0);
	gen_solutions(argv[1], min_removals, 0, 0);
	return (0);
}
