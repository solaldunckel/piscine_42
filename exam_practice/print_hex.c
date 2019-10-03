#include <stdio.h>

int		ft_atoi(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (str[0] == '-')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - 48;
		else
			return (0);
		i++;
	}
	return (res);
}


void	num_hex(int num)
{
	char hex[] = "0123456789ABCDEF";

	if (num >= 16)
		num_hex(num / 16);
	num = num % 16;
	printf("%c", hex[num % 16]);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	num_hex(ft_atoi(argv[1]));
}
