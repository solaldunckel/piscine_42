#include <stdlib.h>
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

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strstr(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char 	*malloc_chain(char *str, int pos, int num)
{
	int		i;
	char	*occ;
	
	i = 0;
	occ = malloc(sizeof(char) * num + 1);
	while (str[pos] && pos <= num)
	{
		occ[i] = str[pos];
		pos++;
		i++;
	}
	occ[i] = '\0';
	return (occ);
}

int		find_in_chains(char *str, char **argv, int argc)
{
	int		i;

	i = 2;
	while (i < argc)
	{
		if (!ft_strstr(argv[i], str))
			return (0);
		i++;
	}
	return (1);
}

void	max_lenoc(char **argv, int argc)
{
	int		i;
	int		j;
	char	*temp;
	char	*oc;
	
	oc = malloc(sizeof(char) * 100);
	i = 0;
	j = 0;
	while (i < ft_strlen(argv[1]))
	{
		j = i;
		while (j < ft_strlen(argv[1]))
		{
			temp = malloc_chain(argv[1], i, j);
			if (find_in_chains(temp, argv, argc))
			{
				if (ft_strlen(oc) >= 1 && (ft_strlen(temp) > ft_strlen(oc)))
					ft_strcpy(oc, temp);
				else if (ft_strlen(oc) == 0)
					ft_strcpy(oc, temp);
			}
			j++;
		}	
		i++;
	}
	ft_putstr(oc);
}


int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	max_lenoc(argv, argc);
	write(1, "\n", 1);
}
