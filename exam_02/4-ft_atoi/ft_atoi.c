int		ft_atoi(const char *str)
{
	int		i;
	int		negative;
	int		res;

	i = 0;
	negative = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}	
	if (negative)
		res = -res;
	return (res);
}
