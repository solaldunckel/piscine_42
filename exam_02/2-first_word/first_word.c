#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_word(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\0'))
		{
			ft_putchar(str[i]);
			i++;	
		}
		return ;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	if (argc == 2)
	{
		first_word(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}
