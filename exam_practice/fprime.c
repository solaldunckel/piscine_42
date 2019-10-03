#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = (nb % 10) + 48;
	write(1, &nb, 1);
}

int		is_prime(int nb)
{
	int		i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

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

void	fprime(int num)
{
	int		i;

	i = 2;
	int num2 = num;
	while (i < num2)
	{
		while (!is_prime(i))
			i++;
		if (num % i == 0)
		{
			printf("%d", i);
			num = num / i;
			if (num == 1)
				break;
			printf("*");
		}
		else
		{
			i++;
		}
	}
	if (num == num2)
		printf("%d", num);
}

int		main(int argc, char **argv)
{
	int		num;
	if (argc != 2)
	{
		ft_putstr("\n");
		return (0);
	}
	num = ft_atoi(argv[1]);
	fprime(num);
}
