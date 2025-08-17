

int		ft_atoi(char *str)
{
	int c; //karakterleri sirayla okumak icin
	int sign; 
	int result; 

	c = 0;
	sign = 1;
	result = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ') //skip the spaces
		c++;
	while (str[c] == '+' || str[c] == '-') //check the sign
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9') //rakamlari sirayla okuyor ve sayiya ceviriyor
	{
		result = (str[c] - '0') + (result * 10);
		c++;
	}
	return (result * sign);
}
