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

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "z\n", 2);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == 'z')
		{
			write(1, &argv[1][i], 1);
			write(1, "\n", 1);
			return (0);
		}
		i++;
	}
	write(1, "z\n", 2);
}
