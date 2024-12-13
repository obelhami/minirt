#include "minirt.h"

inline int	clamp(double min, double max, int var)
{
	if (var <= min)
		return (min);
	else if (var >= max)
		return (max);
	else
		return (var);
}

inline double	max(double min, double value)
{
	if (value < min)
		return (min);
	else
		return (value);
}
