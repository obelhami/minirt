#include "minirt.h"

char	**ft_free(char **ptr)
{
    int i;

    i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}
