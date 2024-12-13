BOOL	hit_any_object()
{
	BOOL	hit_anything;

	hit_anything = FALSE;
	while (world != NULL)
	{
		if (world->hit(world->object, interval, rec, ray))
		{
			hit_anything = TRUE;
			interval.max = rec->t;
		}
		world = world->next;
	}
	return (hit_anything);
}
