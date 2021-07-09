#include "cub3d.h"

t_sprt	*new_sprt(double x, double y)
{
	t_sprt	*sprt;

	sprt = (t_sprt *)malloc(sizeof(t_sprt));
	if (!sprt)
		return (NULL);
	sprt->sx = x;
	sprt->sy = y;
	sprt->len = 0;
	sprt->next = NULL;
	return (sprt);
}
