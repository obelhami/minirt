#include "minirt.h"

void	get_bases_centers(t_cylinder *cylinder, T_POINT3 **upper_base,
		T_POINT3 **lower_base)
{
	T_POINT3	*base1;
	T_POINT3	*base2;

	base1 = addition_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	base2 = subtraction_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	if (dot_product(subtraction_op(&cylinder->center, base1),
				&cylinder->axis_vec) > 0.0)
	{
		*lower_base = base1;
		*upper_base = base2;
	}
	else
	{
		*lower_base = base2;
		*upper_base = base1;
	}
}

BOOL	closeto_zero(double value)
{
	value = fabs(value); // TODO: create ft_fabs
	if (value < 1e-10)
		return (TRUE);
	return (FALSE);
}
