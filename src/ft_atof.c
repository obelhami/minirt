#include "minirt.h"

float ft_atof(char *str)
{
	int	i;
	float	sign;
	double	factorial;
	int	test;

	i = 0;
	sign = 1.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	factorial = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		factorial = (10 * factorial) + str[i] - '0';
		i++;
	}
	test = 10;
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            factorial = factorial + ((double)(str[i] - '0') / test);
            i++;
			test *= 10;
        }
    }
	return (factorial * sign);
}
