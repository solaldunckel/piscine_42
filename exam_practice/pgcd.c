#include <stdio.h>
#include <stdlib.h>

int		pgcd(int nb1, int nb2)
{
	int		i;

	if (nb2 > nb1)
		i = nb1;
	else
		i = nb2;
	while (i > 0)
	{
		if (nb1 % i == 0 && nb2 % i == 0)
			return (i);
		i--;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	nb1 = atoi(argv[1]);
	nb2 = atoi(argv[2]);
	printf("%d", pgcd(nb1, nb2));
}
