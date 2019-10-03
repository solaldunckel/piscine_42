#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		is_used(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	reunion(char *av1, char *av2)
{
	char 	used[256];

	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (av1[i])
	{
		if (!is_used(av1[i], used))
		{
			write(1, &av1[i], 1);
			used[j++] = av1[i];
		}
		i++;
	}
	i = 0;
	while (av2[i])
	{
		if (!is_used(av2[i], used))
		{
			write(1, &av2[i], 1);
			used[j++] = av2[i];
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	reunion(argv[1], argv[2]);
	ft_putstr("\n");
}
