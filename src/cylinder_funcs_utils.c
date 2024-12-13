#include "minirt.h"

void	get_bases_centers(t_cylinder *cylinder)
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
		cylinder->lower_base = base1;
		cylinder->upper_base = base2;
	}
	else
	{
		cylinder->lower_base = base2;
		cylinder->upper_base = base1;
	}
}

inline BOOL	closeto_zero(double value)
{
	value = fabs(value); // TODO: create ft_fabs
	if (value < 1e-10)
		return (TRUE);
	return (FALSE);
}
