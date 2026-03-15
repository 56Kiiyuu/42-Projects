#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int	ch = fgetc(f);
	if (ch == EOF && ferror(f))
		return (-1);
	while (ch != EOF)
	{
		if (!isspace(ch))
		{
			ungetc(ch, f);
			break ;
		}
		ch = fgetc(f);
	}

	if (ferror(f))
		return (-1);
	return (1);
}

int match_char(FILE *f, char c)
{
	int	ch = fgetc(f);
	if (ch == c)
		return (1);
	if (ch != EOF)
		ungetc(ch, f);
    return (-1);
}

int scan_char(FILE *f, va_list ap)
{
	char *cp = va_arg(ap, char *);
	int ch = fgetc(f);
	if (ch == EOF)
		return -1;
	*cp = ch;
	return 1;
}

int scan_int(FILE *f, va_list ap)
{
	int *ip = va_arg(ap, int *);
	int ch = fgetc(f);
	int sign = 1;
	int val = 0;
	if (ch == '-' || ch == '+')
	{
		if (ch == '-')
			sign = -1;
		ch = fgetc(f);
	}
	if (!isdigit(ch))
	{
		if (ch != EOF)
			ungetc(ch, f);
		return -1;
	}
	while (isdigit(ch))
	{
		val = val * 10 + ch - '0';
		ch = fgetc(f);
	}
	if (ch != EOF)
		ungetc(ch, f);
	*ip = val * sign;
	return 1;
}

int scan_string(FILE *f, va_list ap)
{
	char *sp = va_arg(ap, char *);
	int ch = fgetc(f);
	int i = 0;
	while (isspace(ch))
		ch = fgetc(f);
	if (ch == EOF)
		return -1;
	while (ch != EOF && !isspace(ch))
	{
		sp[i++] = ch;
		ch = fgetc(f);
	}
	sp[i] = 0;
	if (ch != EOF)
		ungetc(ch, f);
	return 1;
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}

	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

/*
int main(void)
{
    int x;
    char str[100];
    char c;
    int converted = ft_scanf("%d %s %c", &x, str, &c);
    printf("Converted: %d\n", converted);
    printf("Numero: %d, String: %s, Character: %c\n", x, str, c);
    return 0;
}
*/
