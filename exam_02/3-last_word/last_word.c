#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		count_words(char *str)
{
	int		is_word;
	int		i;
	int		count;

	i = 0;
	is_word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			is_word = 0;
		else if (is_word == 0 && str[i] != ' ' && str[i] != '\t')
		{
			is_word = 1;
			count++;
		}
		i++;
	}
	return (count);

}
#include <stdio.h>
void	last_word(char *str)
{
	int		num_words;
	int		i;
	int		is_word;
	int		count;

	num_words = count_words(str);
	i = 0;
	is_word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			is_word = 0;
		else if (is_word == 0 && str[i] != ' ' && str[i] != '\t')
		{
			is_word = 1;
			count++;
		}
		if (count == num_words && (str[i] != ' ' && str[i] != '\t'))
			ft_putchar(str[i]);
		i++;
	}}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	if (argc == 2)
	{
		last_word(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}
