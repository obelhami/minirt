#include "minirt.h"

int	ft_dblptrlen(char **str)
{
	int i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
