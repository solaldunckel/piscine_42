#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{
			ft_putchar(str[i]);
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('a');
			ft_putchar('\n');
			return;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('a');
		ft_putchar('\n');
		return (0);
	}
	display(argv[1]);
	return (0);
}
