#include "minirt.h"

double random_double(void)
{
	static unsigned long int next = 12345;
    unsigned long int a;
    unsigned long int c;
    unsigned long int m;

	a = 1664525;
	c = 1013904223;
	m = 4294967296;
    next = (a * next + c) % m;
    return ((double)next / (double)m);
}

double	interval_random_double(t_interval interval)
{
	return (interval.min + ((interval.max - interval.min) * random_double()));
}
