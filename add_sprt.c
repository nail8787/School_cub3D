#include "cub3d.h"

void	add_sprt_back(t_img *img, t_sprt *new)
{
	t_sprt *head;

	head = img->sprt;
	if (head == NULL)
		img->sprt = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}
